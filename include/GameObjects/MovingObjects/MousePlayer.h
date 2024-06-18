#pragma once

#include "MovingObject.h"

class MousePlayer : public MovingObject {

private:
	sf::Vector2f getDirection() const;

public:
	MousePlayer(sf::Vector2f pos);

	virtual void move(sf::Time deltaTime) override;
};