#pragma once

#include "EnemyObject.h"

class CatEnemy : public EnemyObject {

private:
	sf::Vector2f getDirection();
	enum Direction {
		UP, Down, Left, Right};

	Direction m_direction;
public:
	sf::Time m_time;
	CatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime) override;
	virtual void handleCollision(WallObject& other) override;
	using EnemyObject::handleCollision;
};