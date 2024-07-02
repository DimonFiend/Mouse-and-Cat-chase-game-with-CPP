#include "FreezePresent.h"
#include "Resources.h"

FreezePresent::FreezePresent(sf::Vector2f pos) : PresentObject(pos)
{
	m_sprite.setTextureRect(Resources::instance().getTextureRect(Objects::Present_Freeze));
	auto posOrigin = sf::Vector2f(pos.x + 32, pos.y + 32);
	auto textureSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	m_sprite.setPosition(posOrigin);
}

void FreezePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void FreezePresent::handleCollision(MousePlayer& other)
{
	Resources::instance().playSound(Sounds::FreezeFx);
	this->setToDelete();
}