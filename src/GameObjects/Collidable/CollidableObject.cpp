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
        // Reduce the intersection by 5 pixels on each side
        intersection.left += 5;
        intersection.top += 5;
        intersection.width -= 5;
        intersection.height -= 5;

        return m_sprite.getGlobalBounds().intersects(intersection);

    }
    return false;
}