#include "FreezePresent.h"
#include "Resources.h"

FreezePresent::FreezePresent(sf::Vector2f pos)
	: PresentObject(pos, Resources::instance().getTextureRect(Objects::Present_Freeze))
{}

void FreezePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void FreezePresent::handleCollision(MousePlayer& other)
{
	Resources::instance().playSound(Sounds::TearPresent);
	Resources::instance().playSound(Sounds::FreezeFx);
	this->setToDelete();
}