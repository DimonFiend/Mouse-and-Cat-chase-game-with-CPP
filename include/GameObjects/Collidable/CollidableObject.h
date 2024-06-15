#pragma once
#include "GameObject.h"

class CollidableObject : public GameObject{
private:

public:
	CollidableObject(sf::Texture* texture,sf::Vector2f pos);
	virtual bool doubleDispatch(GameObject* other) = 0;
};