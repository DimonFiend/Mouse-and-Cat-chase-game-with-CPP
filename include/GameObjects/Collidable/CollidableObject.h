#pragma once
#include "GameObject.h"

class MovingObject;
class CollidableObject : public GameObject{
private:
	bool m_toDelete;

public:
	bool getToDelete() const { return m_toDelete; };
	void setToDelete() { m_toDelete = !m_toDelete; };

	CollidableObject(sf::Texture& texture,sf::Vector2f pos);
	virtual bool checkCollision(MovingObject& other) = 0;
	virtual void handleCollision(MovingObject& other) = 0;
};