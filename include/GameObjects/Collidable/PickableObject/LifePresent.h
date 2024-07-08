///=======================================================================
/// \file		LifePresent.h
/// \brief		Header file for the LifePresent class
///The file contains the definition of the DestroyPresent class.
///  The LifePresent class is a derived class from the LifeObject class.
/// its resposible to handle the collision between the LifePresent object and other objects.

#pragma once
#include "PresentObject.h"

class TimePresent;
class DestroyPresent;
class FreezePresent;
class LifePresent : public PresentObject {
public:
	LifePresent(sf::Vector2f pos);
	virtual ~LifePresent() = default;

	//double dispatch
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override { (void)other; };
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};