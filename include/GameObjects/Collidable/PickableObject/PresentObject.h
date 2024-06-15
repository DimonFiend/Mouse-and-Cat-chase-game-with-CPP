#pragma once

#include "PickableObject.h"

class PresentObject : public PickableObject {
private:

public:
	PresentObject(sf::Vector2f pos);
	virtual bool doubleDispatch(GameObject* other) override;
};