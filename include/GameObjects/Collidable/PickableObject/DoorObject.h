#pragma once
#include "PickableObject.h"
#include "SmartCatEnemy.h"
#include "CatEnemy.h"

class DoorObject : public PickableObject {
private:

public:
	DoorObject(sf::Vector2f pos);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CheeseObject& other) override {};
	virtual void handleCollision(KeyObject& other) override {};
	virtual void handleCollision(DoorObject& other) override {};
	virtual void handleCollision(WallObject& other) override {};
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(CatEnemy& other) override;
};