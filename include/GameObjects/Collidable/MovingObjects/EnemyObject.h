#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:
	
public:
	EnemyObject(float speed = 80);

	 void handleCollision(CollidableObject& other) override;
	 void handleCollision(CheeseObject& other) override;
	 void handleCollision(KeyObject& other) override;
	 void handleCollision(MousePlayer& other) override;
	 void handleCollision(SmartCatEnemy& other) override {};
	 void handleCollision(CatEnemy& other) override {};
	 void move(sf::Time deltaTime) override {};
	 virtual void move(sf::Time deltaTime, GameLevel* manager) = 0;
	 virtual void respawn();
};