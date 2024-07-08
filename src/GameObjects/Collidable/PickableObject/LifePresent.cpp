#include "LifePresent.h"
#include "Resources.h"

LifePresent::LifePresent(sf::Vector2f pos)
	:PresentObject(pos, Resources::instance().getTextureRect(Objects::Present_Life))
{}

void LifePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void LifePresent::handleCollision(MousePlayer& other)
{
	this->setToDelete();
	Resources::instance().playSound(Sounds::TearPresent);

}