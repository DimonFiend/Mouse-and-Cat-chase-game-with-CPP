#include "CheeseObject.h"
#include "Resources.h"
#include "MovingObject.h"

CheeseObject::CheeseObject(sf::Vector2f pos)
	: PickableObject(Resources::instance().getCheeseTexture(), pos)
{
	GameObject::setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void CheeseObject::handleCollision(MovingObject& other)
{
	other.handleCollision(*this);
}


bool CheeseObject::checkCollision(MovingObject& other)
{
	return getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}