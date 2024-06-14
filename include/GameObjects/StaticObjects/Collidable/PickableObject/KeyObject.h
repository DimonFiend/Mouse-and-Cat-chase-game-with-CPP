#pragma once

#include "PickableObject.h"

class KeyObject : public PickableObject {
private:

public:
	KeyObject(sf::Vector2f pos);
	virtual bool doubleDispatch(GameObject* other) override;
};