#include "SmartCatEnemy.h"
#include "Resources.h"
#include "Configs.h"

SmartCatEnemy::SmartCatEnemy(sf::Vector2f pos)
	:EnemyObject(SMART_CAT_SPEED)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	auto rect = Resources::instance().getTextureRect(Objects::Cat);
	m_sprite.setTextureRect(rect);
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setColor(sf::Color::Red);
	m_sprite.setPosition(posOrigin);
}

void SmartCatEnemy::move(sf::Time deltaTime)
{
	//sf::Vector2f movement = getDirection();
	//m_sprite.move(EnemyObject::getSpeed());
}

void SmartCatEnemy::handleCollision(WallObject& other)
{
	m_sprite.setPosition(MovingObject::getLastPos());
}
