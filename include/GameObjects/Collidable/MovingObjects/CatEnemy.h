#pragma once

#include "EnemyObject.h"

class CatEnemy : public EnemyObject {

private:
	sf::Vector2f getDirection();
	enum Direction {UP, Down, Left, Right};
	Direction m_direction;

	void handleObstruct();
public:
	sf::Clock m_time;
	CatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	using EnemyObject::handleCollision;
};