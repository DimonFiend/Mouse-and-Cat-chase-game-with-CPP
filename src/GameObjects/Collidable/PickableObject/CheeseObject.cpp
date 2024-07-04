#include "CheeseObject.h"
#include "Resources.h"
#include "MovingObject.h"

unsigned int CheeseObject::m_cheeseCount = 0;

CheeseObject::CheeseObject(sf::Vector2f pos)
	: PickableObject(pos, Resources::instance().getTextureRect(Objects::Cheese))
{
	m_cheeseCount++;
}

void CheeseObject::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void CheeseObject::handleCollision(MousePlayer& other)
{
	this->setToDelete();
}