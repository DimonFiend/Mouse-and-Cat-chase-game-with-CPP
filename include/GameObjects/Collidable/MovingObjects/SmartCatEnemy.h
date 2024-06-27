#pragma once

#include "EnemyObject.h"

class SmartCatEnemy : public EnemyObject {

private:


public:
	SmartCatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime) override;
};