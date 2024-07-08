///=======================================================================
/// \file		FreezePresent.h
/// \brief		Header file for the FreezePresent class
///The file contains the definition of the FreezePresent class.
///  The FreezePresent class is a derived class from the FreezeObject class.
/// its resposible to handle the collision between the FreezeePresent object and other objects.

#pragma once
#include "PresentObject.h"

class TimePresent;
class DestroyPresent;
class FreezePresent : public PresentObject {
public:
	FreezePresent(sf::Vector2f pos);

	//Double dispatch
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override { (void)other; };
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};