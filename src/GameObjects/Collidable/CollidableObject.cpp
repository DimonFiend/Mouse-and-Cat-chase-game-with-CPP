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
        // Reduce the intersection by 15 pixels on each side
        intersection.left += 20;
        intersection.top += 20;
        intersection.width -= 40;
        intersection.height -= 40;
    }
    
    return m_sprite.getGlobalBounds().intersects(intersection);
}