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
		// Calculate the margin by subtracting 5 pixels from the intersection bounds
		sf::FloatRect marginBounds = intersection;
		marginBounds.top +=5;
		marginBounds.left += 5;
		marginBounds.width -= 5;
		marginBounds.height -= 5;


		return marginBounds.intersects(other.getBounds());
	}
	return false;
}