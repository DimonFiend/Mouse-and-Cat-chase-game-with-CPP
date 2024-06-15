#pragma once

#include "CollidableObject.h"

class WallObject : public CollidableObject {

public:
	WallObject(sf::Vector2f pos);
	virtual bool doubleDispatch(CollidableObject* other) override;
};