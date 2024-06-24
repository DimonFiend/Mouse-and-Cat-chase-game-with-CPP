#pragma once

#include "EnemyObject.h"

class CatEnemy : public EnemyObject {

private:
	sf::Vector2f getDirection();

public:
	CatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime) override;
};