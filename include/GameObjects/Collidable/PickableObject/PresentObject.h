///=======================================================================
/// \file    PresentObject.h
/// \brief  A class that represents a present object in the game.
/// 		This class is a derived class from PickableObject.
///         and a base class for all the present objects in the game.
/// 	    implemented few double dispatch functions that are not relevant to the present object.

#pragma once

#include "PickableObject.h"
#include "MovingObject.h"
class Presents;
class PresentObject : public PickableObject {
private:

public:
	PresentObject(sf::Vector2f pos, sf::IntRect obj);
	virtual ~PresentObject() = default;

	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(WallObject& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(CatEnemy& other) override { (void)other; };
};