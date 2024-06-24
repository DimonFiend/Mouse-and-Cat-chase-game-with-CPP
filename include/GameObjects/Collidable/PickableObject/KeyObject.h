#pragma once

#include "PickableObject.h"

class MovingObject;

class KeyObject : public PickableObject {
private:

public:
	KeyObject(sf::Vector2f pos);
	virtual bool checkCollision(MovingObject& other) override;
	virtual void handleCollision(MovingObject& other) override;
};