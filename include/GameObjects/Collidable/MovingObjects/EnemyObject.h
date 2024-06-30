#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:

public:
	EnemyObject(float speed = 80, Direction dir = static_cast<Direction>(rand() % 4));

	virtual void move(sf::Time deltaTime) override { (void)deltaTime; };
	virtual void move(sf::Time deltaTime, GameLevel* manager) = 0;
	sf::Vector2f calcRelativePos(sf::Vector2f pos) const;
	virtual void respawn();
};