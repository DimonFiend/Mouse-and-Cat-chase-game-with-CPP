#pragma once
#include "PickableObject.h"

class MovingObject;
class CheeseObject : public PickableObject {
private:
	static unsigned int m_cheeseCount;
public:
	CheeseObject(sf::Vector2f pos);
	virtual ~CheeseObject() { m_cheeseCount--; };
	virtual bool checkCollision(MovingObject& other) override;
	virtual void handleCollision(MovingObject& other) override;
};