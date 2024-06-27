#include "DoorObject.h"
#include "Resources.h"
#include "MovingObject.h"

DoorObject::DoorObject(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Door));
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void DoorObject::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void DoorObject::handleCollision(MousePlayer& other)
{
	other.handleCollision(*this);
}

void DoorObject::handleCollision(EnemyObject& other)
{
	other.handleCollision(*this);
}