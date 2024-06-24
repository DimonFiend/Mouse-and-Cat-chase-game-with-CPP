#pragma once
#include "GameObject.h"

class MovingObject;
class CollidableObject : public GameObject{
private:
	bool m_toDelete;

public:
	CollidableObject();

	bool getToDelete() const { return m_toDelete; };
	void setToDelete() { m_toDelete = !m_toDelete; };
	virtual bool checkCollision(MovingObject& other) = 0;
	virtual void handleCollision(MovingObject& other) = 0;
};