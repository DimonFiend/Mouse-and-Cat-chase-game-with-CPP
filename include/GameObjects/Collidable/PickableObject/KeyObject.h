#pragma once
#include "PickableObject.h"

class KeyObject : public PickableObject {
private:

public:
	KeyObject(sf::Vector2f pos);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(EnemyObject& other) override;
};