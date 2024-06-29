#pragma once

#include "EnemyObject.h"
#include <iostream>
class SmartCatEnemy : public EnemyObject {

private:


public:
	SmartCatEnemy(sf::Vector2f pos);
	virtual ~SmartCatEnemy() = default;
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override {};
	using EnemyObject::handleCollision;
};