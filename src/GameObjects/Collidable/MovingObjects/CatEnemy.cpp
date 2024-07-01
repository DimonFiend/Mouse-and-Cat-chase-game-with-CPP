#include "CatEnemy.h"
#include "Resources.h"
#include "Configs.h"
#include "GameLevel.h"
CatEnemy::CatEnemy(sf::Vector2f pos)
	:EnemyObject(CAT_SPEED)
{
	auto rect = Resources::instance().getTextureRect(Objects::Cat);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
	MovingObject::setSpawn(posOrigin);
	MovingObject::setLastPos(posOrigin);
	MovingObject::setAnimator();
	m_timer.restart();
}

void CatEnemy::move(sf::Time deltaTime, GameLevel* manager)
{
	if (EnemyObject::checkFreezeStatus())
	{
		return;
	}

	auto posIndex = MovingObject::toGridIndex(m_sprite.getPosition());
	MovablePath path = manager->getPath(posIndex);
    sf::Vector2f dir = getDirection(path);

	MovingObject::setLastPos(m_sprite.getPosition());
	auto movement = dir * EnemyObject::getSpeed() * deltaTime.asSeconds();
	m_sprite.move(movement);
	MovingObject::Animate(deltaTime, m_direction);
	this->checkMapBounds(manager);
}

sf::Vector2f CatEnemy::getDirection(const MovablePath& path)
{
	auto relativePos = EnemyObject::calcRelativePos(m_sprite.getPosition());
	auto time = m_timer.getElapsedTime();
	auto offset = rand() % 5;

    if (path.size() >= 3 && time.asSeconds() > (1.5 + offset) 
		&& (std::abs(relativePos.x - 32) < 4) && (std::abs(relativePos.y - 32) < 15))
    {
		return this->switchDirection(path);
	}
	else
	{
		return MovingObject::enumToVector();
    }
}

sf::Vector2f CatEnemy::switchDirection(const MovablePath& path)
{
	auto generate = rand() % static_cast<int>(path.size());
	auto keep_last = rand() % 3;

	auto pathVectorX = path[generate].x - std::floor(m_sprite.getPosition().x / 64);
	auto pathVectorY = path[generate].y - std::floor(m_sprite.getPosition().y / 64);

	if (keep_last == 0){return MovingObject::enumToVector();}

	if (pathVectorX == 0 && pathVectorY == 1 && m_direction != Up){m_direction = Down;}
	else if (pathVectorX == 0 && pathVectorY == -1 && m_direction != Down){m_direction = Up;}
	else if (pathVectorX == 1 && pathVectorY == 0 && m_direction != Left){m_direction = Right;}
	else if (pathVectorX == -1 && pathVectorY == 0 && m_direction != Right){m_direction = Left;}
	m_timer.restart();
	return MovingObject::enumToVector();
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
		this->handleObstruct();
	}
}

void CatEnemy::handleCollision(MousePlayer& other)
{
	if (!isFrozen())
	{
		other.handleCollision(*this);
	}
}

void CatEnemy::handleCollision(WallObject& other)
{
	(void)other;
    this->handleObstruct();
}

void CatEnemy::handleCollision(DoorObject& other)
{
	(void)other;
    this->handleObstruct();
}

void CatEnemy::handleObstruct()
{
	m_sprite.setPosition(MovingObject::getLastPos());
	m_direction = static_cast<Direction>(rand() % 4);
}