///=======================================================================
/// \file	PickableObject.h
/// \brief	A base class that represents a pickable object in the game.

#pragma once 

#include "CollidableObject.h"
#include "MousePlayer.h"
#include "CatEnemy.h"

class MovingObject;

class PickableObject : public CollidableObject
{
private:

public:
	PickableObject(sf::Vector2f pos, sf::IntRect obj):
		CollidableObject(pos, obj)
	{};
	virtual ~PickableObject() = default;
};