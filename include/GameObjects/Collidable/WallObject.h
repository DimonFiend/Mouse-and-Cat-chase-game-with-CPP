#pragma once

#include "CollidableObject.h"
#include "MousePlayer.h"

class WallObject : public CollidableObject {

public:
	WallObject(sf::Vector2f pos);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CatEnemy& other) override;
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(CheeseObject& other) override {};
	virtual void handleCollision(KeyObject& other) override {};
	virtual void handleCollision(DoorObject& other) override {};
	virtual void handleCollision(WallObject& other) override {};
};