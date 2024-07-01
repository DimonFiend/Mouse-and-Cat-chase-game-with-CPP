#pragma once

#include "PickableObject.h"
#include "MovingObject.h"
class Presents;
class PresentObject : public PickableObject {
private:

public:
	PresentObject(sf::Vector2f pos);

	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(WallObject& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(CatEnemy& other) override { (void)other; };
};