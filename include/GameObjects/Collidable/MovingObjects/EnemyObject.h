#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:
	
public:
	EnemyObject(float speed = 80);

	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(EnemyObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	virtual void handleCollision(WallObject& other) override;

	virtual void handleCollision(CheeseObject& other) override;
	virtual void handleCollision(KeyObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
};