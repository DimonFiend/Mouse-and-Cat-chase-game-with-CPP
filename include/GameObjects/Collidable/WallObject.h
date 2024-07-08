#pragma once

#include "CollidableObject.h"
#include "MousePlayer.h"

class WallObject : public CollidableObject {

public:
	WallObject(sf::Vector2f pos);

	//Double dispatch
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CatEnemy& other) override;
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(WallObject& other) override { (void)other; };
	virtual void handleCollision(TimePresent& other) override { (void)other; };
	virtual void handleCollision(FreezePresent& other) override { (void)other; };
	virtual void handleCollision(DestroyPresent& other) override { (void)other; };
	virtual void handleCollision(LifePresent& other) override { (void)other; };
};