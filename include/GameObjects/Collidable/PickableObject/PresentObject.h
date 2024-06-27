#pragma once

#include "PickableObject.h"
#include "MovingObject.h"
class Presents;
class PresentObject : public PickableObject {
private:
	std::unique_ptr<Presents> m_present;
public:
	PresentObject(sf::Vector2f pos, std::unique_ptr<Presents> obj);
	virtual bool checkCollision(CollidableObject& other) override;
	virtual void handleCollision(CollidableObject& other) override;
};