#include "CollidableObject.h"
#include "MovingObject.h"

CollidableObject::CollidableObject(sf::Texture& texture, sf::Vector2f pos)
	: GameObject(texture, pos), m_toDelete(false)
{}

bool CollidableObject::checkCollision(MovingObject& other)
{
	return getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}