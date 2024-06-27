#pragma once

#include "CollidableObject.h"
#include "MousePlayer.h"
#include "EnemyObject.h"

class MovingObject;
class WallObject : public CollidableObject {

public:
	WallObject(sf::Vector2f pos);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(EnemyObject& other) override;
};