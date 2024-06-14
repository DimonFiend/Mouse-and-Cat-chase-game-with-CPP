#pragma once

#include "CollidableObject.h"

class WallObject : public CollidableObject {

public:
	virtual bool doubleDispatch(GameObject* other) override;
	virtual void draw(sf::RenderWindow& window) override;
};