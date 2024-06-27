#include "CollidableObject.h"
#include "MovingObject.h"

CollidableObject::CollidableObject()
	:m_toDelete(false)
{}

bool CollidableObject::checkCollision(CollidableObject& other)
{
	return m_sprite.getGlobalBounds().intersects(other.getBounds());
}