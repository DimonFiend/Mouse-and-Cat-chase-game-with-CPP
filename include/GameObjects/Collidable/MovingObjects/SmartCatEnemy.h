#pragma once

#include "EnemyObject.h"

class SmartCatEnemy : public EnemyObject {

private:


public:
	SmartCatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override {};
	using EnemyObject::handleCollision;
};