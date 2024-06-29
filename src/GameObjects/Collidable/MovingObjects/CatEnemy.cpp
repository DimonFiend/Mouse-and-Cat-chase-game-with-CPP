#include "CatEnemy.h"
#include "Resources.h"
#include "Configs.h"
#include "GameLevel.h"
CatEnemy::CatEnemy(sf::Vector2f pos)
	:EnemyObject(CAT_SPEED), m_direction(static_cast<Direction>(rand() %  4))
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	auto rect = Resources::instance().getTextureRect(Objects::Cat);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
	MovingObject::setSpawn(posOrigin);
	MovingObject::setLastPos(posOrigin);
	m_timer.restart();
}

void CatEnemy::move(sf::Time deltaTime, GameLevel* manager)
{
	MovablePath path = manager->getPath(m_sprite.getPosition());
    sf::Vector2f movement = getDirection(path);

	MovingObject::setLastPos(m_sprite.getPosition());
	m_sprite.move(movement * EnemyObject::getSpeed() * deltaTime.asSeconds());
	this->checkMapBounds(manager);
}

sf::Vector2f CatEnemy::getDirection(const MovablePath& path)
{
	auto relativePos = calcRelativePos(m_sprite.getPosition());
	auto time = m_timer.getElapsedTime();
	auto offset = rand() % 5;

    if (path.size() >= 3 && time.asSeconds() > (1.5 + offset) 
		&& (std::abs(relativePos.x - 32) < 4) && (std::abs(relativePos.y - 32) < 10))
    {
		return switchDirection(path);
	}
	else
	{
		return enumToVector();
    }
}

sf::Vector2f CatEnemy::switchDirection(const MovablePath& path)
{
	auto generate = rand() % static_cast<int>(path.size());
	auto rand_x = rand() % 2 + 2;
	auto rand_y = rand() % 2;
	auto keep_last = rand() % 3;

	if (keep_last == 0)
	{
		return enumToVector();
	}

	if (path[generate].x == 0 && path[generate].y == 1
		&& m_direction == Right || m_direction == Left)
	{
		m_direction = static_cast<Direction>(rand_y);
	}
	else if (path[generate].x == 0 && path[generate].y == -1
		&& m_direction == Right || m_direction == Left)
	{
		m_direction = static_cast<Direction>(rand_y);
	}
	else if (path[generate].x == 1 && path[generate].y == 0
		&& m_direction == Up || m_direction == Down)
	{
		m_direction = static_cast<Direction>(rand_x);
	}
	else if (path[generate].x == -1 && path[generate].y == 0
		&& m_direction == Up || m_direction == Down)
	{
		m_direction = static_cast<Direction>(rand_x);
	}
	m_timer.restart();
	return enumToVector();
}

sf::Vector2f CatEnemy::enumToVector() const
{
	switch (m_direction)
	{
	case Up:
		return sf::Vector2f(0, -1);
	case Down:
		return sf::Vector2f(0, 1);
	case Left:
		return sf::Vector2f(-1, 0);
	case Right:
		return sf::Vector2f(1, 0);
	}
	return sf::Vector2f(0, 0);
}

sf::Vector2f CatEnemy::calcRelativePos(sf::Vector2f pos) const
{
	auto loc_y = std::floor(pos.y / 64);
	auto loc_x = std::floor(pos.x / 64);

	auto pos_y = (pos.y) - loc_y * 64;
	auto pos_x = (pos.x) - loc_x * 64;

	return sf::Vector2f(pos_x, pos_y);
}

void CatEnemy::checkMapBounds(GameLevel* manager)
{
	auto pos = m_sprite.getPosition();
	auto map_size = manager->getMapSize();
	auto limit = m_sprite.getLocalBounds().getSize();
	if (pos.x < (limit.x / 2) || pos.x > map_size.x - (limit.x / 2)
		|| pos.y < limit.y / 2 || pos.y > map_size.y - (limit.y / 2))
	{
		this->handleObstruct();
	}
}

void CatEnemy::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void CatEnemy::handleCollision(CatEnemy& other)
{
	if (this != &other)
	{
		m_direction = static_cast<Direction>(rand() % 4);
		m_sprite.setPosition(MovingObject::getLastPos());
	}
}

void CatEnemy::handleCollision(MousePlayer& other)
{
	other.handleCollision(*this);
}

void CatEnemy::handleCollision(WallObject& other)
{
	(void)other;
    handleObstruct();
}

void CatEnemy::handleCollision(DoorObject& other)
{
	(void)other;
    handleObstruct();
}

void CatEnemy::handleObstruct()
{
    m_sprite.setPosition(MovingObject::getLastPos());
    m_direction = static_cast<Direction>(rand() % 4);
}
