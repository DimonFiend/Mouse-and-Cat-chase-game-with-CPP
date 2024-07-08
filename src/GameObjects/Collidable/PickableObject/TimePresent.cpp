#include "TimePresent.h"
#include "Resources.h"

TimePresent::TimePresent(sf::Vector2f pos)
	:PresentObject(pos, Resources::instance().getTextureRect(Objects::Present_Time))
{}

void TimePresent::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void TimePresent::handleCollision(MousePlayer& other)
{
	this->setToDelete();
	Resources::instance().playSound(Sounds::TearPresent);
}