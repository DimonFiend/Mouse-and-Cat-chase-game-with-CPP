#pragma once 

#include "CollidableObject.h"

class PickableObject : public CollidableObject
{
private:
	bool m_toDelete;

public:
	PickableObject(sf::Vector2f pos);
	bool getToDelete() const { return m_toDelete; };
	void setToDelete() { m_toDelete = !m_toDelete; };
};