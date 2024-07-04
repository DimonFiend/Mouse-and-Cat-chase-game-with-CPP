#include "MousePlayer.h"
#include "Resources.h"
#include "ObjectsInclude.h"
#include "EnemyObject.h"
#include "Configs.h"
#include "GameLevel.h"
#include "Utilities.h"

unsigned int MousePlayer::m_lives = MAX_LIVES;
unsigned int MousePlayer::m_score = 0;

MousePlayer::MousePlayer(sf::Vector2f pos, GameLevel* manager)
	:MovingObject(MOUSE_SPEED, pos, Resources::instance().getTextureRect(Objects::Mouse))
	, m_keys(0)
	, m_manager(manager)
{}


void MousePlayer::respawn()
{
	m_sprite.setPosition(MovingObject::getSpawn());
}

void MousePlayer::setScore(int score)
{
	m_score += score;
}

void MousePlayer::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	MovingObject::setLastPos(m_sprite.getPosition());

	m_sprite.move(movement * MovingObject::getSpeed() * deltaTime.asSeconds());
	MovingObject::Animate(deltaTime, m_direction);

	this->checkMapBounds();
}

//ensures the player stays in the map bounds
void MousePlayer::checkMapBounds()
{
	auto pos = m_sprite.getPosition();
	auto map_size = m_manager->getMapSize();
	auto limit = m_sprite.getLocalBounds().getSize();
	if (pos.x < (limit.x / 2) || pos.x > map_size.x - (limit.x / 2)
		|| pos.y < limit.y / 2 || pos.y > map_size.y - (limit.y /2))
	{
		m_sprite.setPosition(MovingObject::getLastPos());
	}
}

//gets the direction of the player based on the keyboard input
sf::Vector2f MousePlayer::getDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = Right;
	}
	else
	{
		m_direction = Idle;
	}


	return enumToVector();
}

//=============================================================================
/*                            Collision handlers                             */

void MousePlayer::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void MousePlayer::handleCollision(DoorObject& other)
{
	if (m_keys > 0)
	{
		m_keys--;
		other.handlePlayer(m_manager);
		this->setScore(DOOR_SCORE);
	}
	else
	{
		m_sprite.setPosition(MovingObject::getLastPos());
	}
}

void MousePlayer::handleCollision(CheeseObject& other)
{
	this->setScore(CHEESE_SCORE);
	other.handleCollision(*this);
	Resources::instance().playSound(Sounds::MouseEat);
}
void MousePlayer::handleCollision(KeyObject& other)
{
	m_keys++;
	other.handleCollision(*this);
	Resources::instance().playSound(Sounds::KeyPickup);
}

void MousePlayer::handleCollision(WallObject& other)
{
	(void)other;
	m_sprite.setPosition(MovingObject::getLastPos());
}

void MousePlayer::handleCollision(MousePlayer& other)
{
	(void)other;
}

void MousePlayer::handleCollision(CatEnemy& other)
{
	(void)other;
	this->handleEnemy();
}

void MousePlayer::handleCollision(SmartCatEnemy& other)
{
	(void)other;
	this->handleEnemy();
}

void MousePlayer::handleEnemy()
{
	m_lives--;
	m_manager->respawn();
}

void MousePlayer::handleCollision(DestroyPresent& other)
{
	other.handleCollision(*this);
	Resources::instance().playSound(Sounds::TearPresent);
	m_manager->destroyEnemie();
	this->setScore(PRESENT_SCORE);
}

void MousePlayer::handleCollision(TimePresent& other)
{
	other.handleCollision(*this);
	m_manager->addTime(TIME_PRESENT);
	Resources::instance().playSound(Sounds::TearPresent);
	this->setScore(PRESENT_SCORE);
}

void MousePlayer::handleCollision(FreezePresent& other)
{
	other.handleCollision(*this);
	m_manager->freezeEnemies();
	Resources::instance().playSound(Sounds::TearPresent);
	this->setScore(PRESENT_SCORE);
}

void MousePlayer::handleCollision(LifePresent& other)
{
	other.handleCollision(*this);
	m_lives++;
	Resources::instance().playSound(Sounds::TearPresent);
	this->setScore(PRESENT_SCORE);
}

/*-----------------------------End of collision handlers-----------------------------*/
//=====================================================================================