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
	virtual void handleCollision(EnemyObject& other) override { other.handleCollision(*this);};

};