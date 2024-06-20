#pragma once

#include "CollidableObject.h"

class MovingObject;
class WallObject : public CollidableObject {

public:
	WallObject(sf::Vector2f pos);
	virtual bool checkCollision(MovingObject& other) override;
	virtual void handleCollision(MovingObject& other) override;
};