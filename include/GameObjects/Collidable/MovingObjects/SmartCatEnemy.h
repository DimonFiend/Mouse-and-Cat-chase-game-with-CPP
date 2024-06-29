#pragma once

#include "EnemyObject.h"
#include <iostream>
class SmartCatEnemy : public EnemyObject {

private:


public:
	SmartCatEnemy(sf::Vector2f pos);
	virtual ~SmartCatEnemy() = default;
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(CatEnemy& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
};