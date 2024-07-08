///=======================================================================
/// file FloorObject.h
///
/// the FloorObject class is a derived class from the GameObject class,
/// representing the floor of the game.
#pragma once

#include "GameObject.h"

class FloorObject : public GameObject {
private:

public:
	FloorObject(sf::Vector2f pos);
};