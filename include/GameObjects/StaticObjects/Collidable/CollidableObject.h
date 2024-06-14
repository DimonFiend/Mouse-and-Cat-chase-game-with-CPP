#pragma once
#include "GameObject.h"

class CollidableObject : public GameObject{
private:

public:
	virtual bool doubleDispatch(GameObject* other) = 0;
};