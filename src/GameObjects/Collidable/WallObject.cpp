#include "WallObject.h"
#include "Resources.h"
#include "MovingObject.h"

WallObject::WallObject(sf::Vector2f pos) :
	CollidableObject(Resources::instance().getWallTexture(), pos)
{
	GameObject::setTextureRect(sf::IntRect(0, 0, 64, 64));
}

bool WallObject::checkCollision(MovingObject& other)
{
	return getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}

void WallObject::handleCollision(MovingObject& other)
{
	//handle collision with moving object, set to last position
}