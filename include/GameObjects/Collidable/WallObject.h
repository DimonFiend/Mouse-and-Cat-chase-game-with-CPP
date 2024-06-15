#pragma once

#include "CollidableObject.h"

class WallObject : public CollidableObject {

public:
	WallObject(sf::Texture* texture ,sf::Vector2f pos);
	//virtual bool doubleDispatch(GameObject* other) override;
};