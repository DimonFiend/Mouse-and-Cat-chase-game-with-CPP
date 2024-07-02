#pragma once
#include "PresentObject.h"

class TimePresent;
class DestroyPresent;
class FreezePresent;
class LifePresent : public PresentObject {
public:
	LifePresent(sf::Vector2f pos);
	virtual ~LifePresent() = default;
	void handleCollision(CollidableObject& other) override;
	void handleCollision(MousePlayer& other) override;
	void handleCollision(TimePresent& other) override { (void)other; };
	void handleCollision(FreezePresent& other) override { (void)other; };
	void handleCollision(DestroyPresent& other) override { (void)other; };
	void handleCollision(LifePresent& other) override { (void)other; };
};