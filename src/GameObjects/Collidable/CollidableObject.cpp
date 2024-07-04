#include "CollidableObject.h"
#include "MovingObject.h"

CollidableObject::CollidableObject(sf::Vector2f pos, sf::IntRect obj)
	:GameObject(pos, obj), m_toDelete(false)
{}

bool CollidableObject::checkCollision(CollidableObject& other)
{
    sf::FloatRect intersection;
    if (m_sprite.getGlobalBounds().intersects(other.getBounds(), intersection))
    {
        // Reduce the intersection by 10 pixels on each side
        intersection.left += 10;
        intersection.top += 10;
        intersection.width -= 20;
        intersection.height -= 20;
    }
    
    return m_sprite.getGlobalBounds().intersects(intersection);
}