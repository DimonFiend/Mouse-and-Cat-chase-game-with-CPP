#pragma once
#include "PresentObject.h"

class DestroyPresent;
class FreezePresent;
class TimePresent : public PresentObject {
public:
	TimePresent(sf::Vector2f pos);
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override { (void)other; };
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};