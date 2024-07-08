///=======================================================================
/// \file		TimePresent.h
/// \brief		Header file for the TimePresent class
///The file contains the definition of the TimePresent class.
///  The TimePresent class is a derived class from the PresentObject class.
/// its resposible to handle the collision between the TimePresent object and other objects.

#pragma once
#include "PresentObject.h"

class DestroyPresent;
class FreezePresent;
class TimePresent : public PresentObject {
public:
	TimePresent(sf::Vector2f pos);

	//Double dispatch
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override { (void)other; };
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};