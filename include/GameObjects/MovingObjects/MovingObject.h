#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {

private:
	float m_speed;


public:
	MovingObject(sf::Texture& texture, sf::Vector2f pos);
	float getSpeed() const {return m_speed;};
	virtual void move(sf::Time deltaTime) = 0;

};