#pragma once

#include "PickableObject.h"

class CheeseObject : public PickableObject {
private:

public:
	CheeseObject(sf::Vector2f pos);
	virtual bool doubleDispatch(GameObject* other) override;
};