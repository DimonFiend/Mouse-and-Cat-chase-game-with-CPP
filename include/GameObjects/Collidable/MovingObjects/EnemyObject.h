#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:
	
public:
	EnemyObject(float speed = 80);

	virtual bool checkCollision(CollidableObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(TimePresent& other) override;
	virtual void handleCollision(FreezePresent& other) override;
	virtual void handleCollision(DestroyPresent& other) override;
	virtual void handleCollision(MovingObject& other) override;
	virtual void handleCollision(CheeseObject& other) override;
	virtual void handleCollision(KeyObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
};