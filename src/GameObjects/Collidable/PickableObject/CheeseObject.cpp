#include "CheeseObject.h"
#include "Resources.h"
#include "MovingObject.h"

unsigned int CheeseObject::m_cheeseCount = 0;

CheeseObject::CheeseObject(sf::Vector2f pos)
{
	m_cheeseCount++;
	m_sprite.setTexture(Resources::instance().getGameTexture());
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Cheese));
	auto posOrigin = sf::Vector2f(pos.x+32,pos.y+32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void CheeseObject::handleCollision(MovingObject& other)
{
	other.handleCollision(*this);
}


bool CheeseObject::checkCollision(MovingObject& other)
{
	return m_sprite.getGlobalBounds().intersects(other.getBounds());
}