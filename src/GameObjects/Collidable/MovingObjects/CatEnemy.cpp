#include "CatEnemy.h"
#include "Resources.h"
#include "GameLevel.h"
CatEnemy::CatEnemy(sf::Vector2f pos)
	:EnemyObject(CAT_SPEED, pos, Resources::instance().getTextureRect(Objects::Cat))
{
	m_direction = static_cast<Direction>(rand() % 4);
	m_timer.restart();
}

void CatEnemy::move(sf::Time deltaTime, GameLevel* manager)
{
	EnemyObject::catSpeak();

	if (EnemyObject::checkFreezeStatus())
	{
		return;
	}

	auto posIndex = MovingObject::toGridIndex(m_sprite.getPosition());
	MovablePath path = manager->getPath(posIndex);
    sf::Vector2f dir = getDirection(path);

	//moves the cat to the next grid
	MovingObject::setLastPos(m_sprite.getPosition());
	auto movement = dir * EnemyObject::getSpeed() * deltaTime.asSeconds();
	m_sprite.move(movement);
	MovingObject::Animate(deltaTime, m_direction);
	this->checkMapBounds(manager);
}

sf::Vector2f CatEnemy::getDirection(const MovablePath& path)
{
	//moves the cat in his current direction or after some randome time limit
	//switches to a new direction
	auto relativePos = EnemyObject::calcRelativePos(m_sprite.getPosition());
	auto time = m_timer.getElapsedTime();
	auto offset = rand() % 5;

    if (path.size() >= 3 && time.asSeconds() > (1.5 + offset) 
		&& (std::abs(relativePos.x - 32) < 4) && (std::abs(relativePos.y - 32) < 10))
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
	//gets a randome possiblle walk path or
	//a randome chance to stay in the current path
	auto generate = rand() % static_cast<int>(path.size());
	auto keep_last = rand() % 3;

	//calculates the direction to the next grid
	auto curToGrid = MovingObject::toGridIndex(m_sprite.getPosition());
	auto pathVectorX = path[generate].x - curToGrid.x;
	auto pathVectorY = path[generate].y - curToGrid.y;

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
	//makes sure the cat stays in the map bounds

	auto pos = m_sprite.getPosition();
	auto map_size = manager->getMapSize();
	auto limit = m_sprite.getLocalBounds().getSize();
	if (pos.x < (limit.x / 2) || pos.x > map_size.x - (limit.x / 2)
		|| pos.y < limit.y / 2 || pos.y > map_size.y - (limit.y / 2))
	{
		this->handleObstruct();
	}
}
//=============================================================================
/*                            Collision handlers                             */

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
		soundOnPlayerHit();
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
	//if can't pass turns to another randome direction
	m_direction = static_cast<Direction>((int(m_direction) + 1 + rand() % 3) % 4);
	m_sprite.setPosition(MovingObject::getLastPos());
}