#pragma once

#include "CollidableObject.h"

class CheeseObject;
class MovingObject : public CollidableObject {

private:
	float m_speed;

public:
	MovingObject(sf::Texture& texture, sf::Vector2f pos);
	float getSpeed() const {return m_speed;};
	virtual void move(sf::Time deltaTime) = 0;
	virtual void handleCollision(CheeseObject& other) = 0;
};