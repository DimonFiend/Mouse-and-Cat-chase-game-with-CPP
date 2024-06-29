#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:
	
public:
	EnemyObject(float speed = 80);

	virtual void move(sf::Time deltaTime) override { (void)deltaTime; };
	virtual void move(sf::Time deltaTime, GameLevel* manager) = 0;
	virtual void respawn();
};