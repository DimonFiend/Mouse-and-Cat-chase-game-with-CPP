#include "MousePlayer.h"
#include "Resources.h"
#include "ObjectsInclude.h"
#include "EnemyObject.h"
#include "Configs.h"
#include "GameLevel.h"

unsigned int MousePlayer::m_lives = 3;
unsigned int MousePlayer::m_score = 0;

MousePlayer::MousePlayer(sf::Vector2f pos)
	:MovingObject(MOUSE_SPEED)
	, m_keys(0)
	, m_manager(nullptr)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	auto rect = Resources::instance().getTextureRect(Objects::Mouse);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
	MovingObject::setSpawn(posOrigin);
	MovingObject::setLastPos(posOrigin);
}

void MousePlayer::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	MovingObject::setLastPos(m_sprite.getPosition());
	m_sprite.move(movement * MovingObject::getSpeed() * deltaTime.asSeconds());

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

void MousePlayer::respawn()
{
	m_sprite.setPosition(MovingObject::getSpawn());
}

sf::Vector2f MousePlayer::getDirection() const
{
	sf::Vector2f movement(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += 1;
	}

	return movement;
}
//=============================================================================
/*                            Collision handlers                             */

void MousePlayer::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}
/*
void MousePlayer::handleCollision(DestroyPresent& other)
{
	other.setToDelete();
	//GameLevel deletes random cat
}

void MousePlayer::handleCollision(TimePresent& other)
{
	other.setToDelete();
	//GameLevel deletes random cat
}

void MousePlayer::handleCollision(FreezePresent& other)
{
	other.setToDelete();
	//GameLevel deletes random cat
}
*/
void MousePlayer::handleCollision(DoorObject& other)
{
	if (m_keys > 0)
	{
		m_keys--;
		other.setToDelete();
		//play door sound
	}
	else
	{
		m_sprite.setPosition(MovingObject::getLastPos());
	}
}

void MousePlayer::handleCollision(CheeseObject& other)
{
	m_score += 10;
	other.setToDelete();
	//play eat sound
}
void MousePlayer::handleCollision(KeyObject& other)
{
	m_keys++;
	other.setToDelete();
	//play key pickup
}

void MousePlayer::handleCollision(CatEnemy& other)
{

}

void MousePlayer::handleCollision(SmartCatEnemy& other)
{

}

void MousePlayer::handleCollision(WallObject& other)
{
	m_sprite.setPosition(MovingObject::getLastPos());
}

void MousePlayer::handleCollision(MousePlayer& other)
{
	//no use for now
}

void MousePlayer::handleCollision(EnemyObject& other)
{
	m_lives--;
	m_manager->respawn();
	//play hit sound
}