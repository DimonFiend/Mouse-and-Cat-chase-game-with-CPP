#include "CatEnemy.h"
#include "Resources.h"

CatEnemy::CatEnemy(sf::Vector2f pos)
	:EnemyObject(70)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	auto rect = Resources::instance().getTextureRect(Objects::Cat);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void CatEnemy::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	m_sprite.move(movement * EnemyObject::getSpeed() * deltaTime.asSeconds());
}

sf::Vector2f CatEnemy::getDirection()
{
	sf::Vector2f movement(0, 0);
	if (rand() % 2 == 0)
	{
		if (rand() % 2 == 0)
		{
			movement.x = 1;
		}
		else
		{
			movement.x = -1;
		}
	}
	else
	{
		if (rand() % 2 == 0)
		{
			movement.y = 1;
		}
		else
		{
			movement.y = -1;
		}
	}
	return movement;
}