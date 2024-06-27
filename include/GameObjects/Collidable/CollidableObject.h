#pragma once
#include "GameObject.h"

class MousePlayer;
class EnemyObject;
class CollidableObject : public GameObject{
private:
	bool m_toDelete;

public:
	CollidableObject();

	bool getToDelete() const { return m_toDelete; };
	void setToDelete() { m_toDelete = !m_toDelete; };
	virtual bool checkCollision(CollidableObject& other);
	virtual void handleCollision(CollidableObject& other) = 0;
	virtual void handleCollision(MousePlayer& other) = 0;
	virtual void handleCollision(EnemyObject& other) = 0;
	//presents collision
};