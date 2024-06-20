#pragma once
#include "PickableObject.h"

class MovingObject;
class CheeseObject : public PickableObject {
private:

public:
	CheeseObject(sf::Vector2f pos);
	virtual bool checkCollision(MovingObject& other) override;
	virtual void handleCollision(MovingObject& other) override;
};