#include "DestroyPresent.h"
#include "Resources.h"
DestroyPresent::DestroyPresent(sf::Vector2f pos)
	: PresentObject(pos, Resources::instance().getTextureRect(Objects::Present_CatDestr))
{}

void DestroyPresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void DestroyPresent::handleCollision(MousePlayer& other)
{
	Resources::instance().playSound(Sounds::RemoveCat);
	this->setToDelete();
}