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
        // Make the intersection rectangle smaller
        float shrinkFactor = 1.5f;
        intersection.left += intersection.width * shrinkFactor / 2;
        intersection.top += intersection.height * shrinkFactor / 2;
        intersection.width *= (1 - shrinkFactor);
        intersection.height *= (1 - shrinkFactor);
    }
    
    return m_sprite.getGlobalBounds().intersects(intersection);
}