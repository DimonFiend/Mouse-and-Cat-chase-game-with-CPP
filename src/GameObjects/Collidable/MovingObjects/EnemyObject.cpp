#include "EnemyObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"
#include "Resources.h"
#include "Utilities.h"
#include "Configs.h"
#include <ctime>

EnemyObject::EnemyObject(float speed, sf::Vector2f pos, sf::IntRect obj)
	: MovingObject(speed, pos, obj), m_frozen(false)
{}

void EnemyObject::respawn()
{
	m_sprite.setPosition(MovingObject::getSpawn());
}

//calculates the direction of the enemy relative to the grid
sf::Vector2f EnemyObject::calcRelativePos(sf::Vector2f pos) const
{
	auto loc_y = std::floor(pos.y / GRID_SIZE);
	auto loc_x = std::floor(pos.x / GRID_SIZE);

	auto pos_y = (pos.y) - loc_y * GRID_SIZE;
	auto pos_x = (pos.x) - loc_x * GRID_SIZE;

	return sf::Vector2f(pos_x, pos_y);
}

//sets the enemy to be frozen
void EnemyObject::setFreeze()
{
	m_frozen = true;
	m_frozenClock.restart();
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::FrozenEnemy));
	m_sprite.setScale(1,1);
}

//checks if the enemy is frozen
bool EnemyObject::checkFreezeStatus()
{
	if (isFrozen())
	{
		auto time = m_frozenClock.getElapsedTime();
		if (time.asSeconds() > FREEZE_PRESENT)
		{
			m_frozen = false;
			return false;
		}

		return true;
	}

	return false;
}

//makes the cat meow at random intervals
void EnemyObject::catSpeak()
{
	srand(static_cast<unsigned int>(time(0)));
	int threshold = rand() % 20 + 4 + rand() % 7;
	auto time = m_speak.getElapsedTime();
	if (time.asSeconds() > threshold)
	{
		Resources::instance().playSound(Sounds::CatMeow);
		m_speak.restart();
	}
}

void EnemyObject::soundOnPlayerHit() const
{
	Resources::instance().playSound(Sounds::CatCollision);
	Resources::instance().playSound(Sounds::CatPunch);
}