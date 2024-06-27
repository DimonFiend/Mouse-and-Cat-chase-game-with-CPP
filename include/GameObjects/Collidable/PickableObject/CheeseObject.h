#pragma once
#include "PickableObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

class CheeseObject : public PickableObject {
private:
	static unsigned int m_cheeseCount;
public:
	CheeseObject(sf::Vector2f pos);
	virtual ~CheeseObject() { m_cheeseCount--; };
	virtual bool checkCollision(CollidableObject& other) override;
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override { other.handleCollision(*this);};
	virtual void handleCollision(CatEnemy& other) override {};
	virtual void handleCollision(SmartCatEnemy& other) override {};
	virtual void handleCollision(CheeseObject& other) {};
	virtual void handleCollision(KeyObject& other) {};
	virtual void handleCollision(DoorObject& other) {};
	virtual void handleCollision(WallObject& other) {};
};