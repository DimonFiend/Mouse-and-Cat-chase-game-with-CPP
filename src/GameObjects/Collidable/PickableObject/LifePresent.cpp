#include "LifePresent.h"
#include "Resources.h"

LifePresent::LifePresent(sf::Vector2f pos)
	:PresentObject(pos)
{
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Present_Life));
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void LifePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void LifePresent::handleCollision(MousePlayer& other)
{
	this->setToDelete();
}