#pragma once
#include "PickableObject.h"
#include "SmartCatEnemy.h"
#include "CatEnemy.h"

class GameLevel;
class DoorObject : public PickableObject {
private:
public:
	DoorObject(sf::Vector2f pos, GameLevel* manager);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(WallObject& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(CatEnemy& other) override;

	void handlePlayer(GameLevel* manager);
};