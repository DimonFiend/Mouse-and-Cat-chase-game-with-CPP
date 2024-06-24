#pragma once

#include "PickableObject.h"

class DoorObject : public PickableObject {
private:

public:
	DoorObject(sf::Vector2f pos);
	virtual bool checkCollision(MovingObject& other) override;
	virtual void handleCollision(MovingObject& other) override;
};