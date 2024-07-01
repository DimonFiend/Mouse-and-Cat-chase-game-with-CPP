#include "TimePresent.h"
#include "Resources.h"

TimePresent::TimePresent(sf::Vector2f pos)
	:PresentObject(pos)
{
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Present_Time));
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void TimePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void TimePresent::handleCollision(MousePlayer& other)
{
	this->setToDelete();
}