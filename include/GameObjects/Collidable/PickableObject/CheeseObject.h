#pragma once
#include "PickableObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

class CheeseObject : public PickableObject {
private:
	static unsigned int m_cheeseCount;
public:
	CheeseObject(sf::Vector2f pos);
	static unsigned int getCheeseCount() { return m_cheeseCount; };
	virtual ~CheeseObject() { m_cheeseCount--; };
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CatEnemy& other) override {};
	virtual void handleCollision(SmartCatEnemy& other) override {};
	virtual void handleCollision(CheeseObject& other) {};
	virtual void handleCollision(KeyObject& other) {};
	virtual void handleCollision(DoorObject& other) {};
	virtual void handleCollision(WallObject& other) {};
};