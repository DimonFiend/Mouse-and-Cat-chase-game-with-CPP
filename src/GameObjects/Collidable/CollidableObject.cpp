#include "CollidableObject.h"
#include "MovingObject.h"

CollidableObject::CollidableObject()
	:m_toDelete(false)
{}

bool CollidableObject::checkCollision(CollidableObject& other)
{
    sf::FloatRect intersection;
    if (m_sprite.getGlobalBounds().intersects(other.getBounds(), intersection))
    {
        // Reduce the intersection by 5 pixels on each side
        intersection.left += 5;
        intersection.top += 5;
        intersection.width -= 10;
        intersection.height -= 10;
    }
    
    return m_sprite.getGlobalBounds().intersects(intersection);
}