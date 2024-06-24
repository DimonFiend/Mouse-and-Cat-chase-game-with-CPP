#pragma once
#include "CollidableObject.h"

class MousePlayer;
class EnemyObject;
class WallObject;
class DoorObject;
class FreezePresent;
class TimePresent;
class DestroyPresent;
class KeyObject;
class CheeseObject;
class MovingObject : public CollidableObject {

private:
	float m_speed;

public:
	MovingObject(float speed = 50);
	float getSpeed() const {return m_speed;};
	virtual void move(sf::Time deltaTime) = 0;

	virtual bool checkCollision(CollidableObject& other) = 0;
	virtual void handleCollision(MousePlayer& other) = 0;
	virtual void handleCollision(EnemyObject& other) = 0;
	virtual void handleCollision(CheeseObject& other) = 0;
	virtual void handleCollision(KeyObject& other) = 0;
	virtual void handleCollision(DestroyPresent& other) = 0;
	virtual void handleCollision(FreezePresent& other) = 0;
	virtual void handleCollision(TimePresent& other) = 0;
	virtual void handleCollision(DoorObject& other) = 0;
	virtual void handleCollision(WallObject& other) = 0;
};