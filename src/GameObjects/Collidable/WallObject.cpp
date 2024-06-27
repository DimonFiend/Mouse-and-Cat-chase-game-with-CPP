#include "WallObject.h"
#include "Resources.h"
#include "MovingObject.h"

WallObject::WallObject(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Wall));
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	auto posOrigin = sf::Vector2f(pos.x + textureSize.x / 2.f, pos.y + textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}


void WallObject::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void WallObject::handleCollision(MousePlayer& other)
{
	other.handleCollision(*this);
}

void WallObject::handleCollision(EnemyObject& other)
{
	other.handleCollision(*this);
}