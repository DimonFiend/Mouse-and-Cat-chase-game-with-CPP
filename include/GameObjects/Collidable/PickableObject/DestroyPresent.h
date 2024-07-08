///=======================================================================
/// \file		DestroyPresent.h
/// \brief		Header file for the DestroyPresent class
///The file contains the definition of the DestroyPresent class.
///  The DestroyPresent class is a derived class from the PresentObject class.
/// its resposible to handle the collision between the DestroyPresent object and other objects.

#pragma once
#include "PresentObject.h"

class TimePresent;
class FreezePresent;
class DestroyPresent : public PresentObject {
public:
	DestroyPresent(sf::Vector2f pos);

	//Double dispatch
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override {(void)other;};
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};