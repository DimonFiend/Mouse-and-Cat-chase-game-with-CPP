#pragma once
#include "PickableObject.h"

class DoorObject : public PickableObject {
private:

public:
	DoorObject(sf::Vector2f pos);
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(EnemyObject& other) override;
};