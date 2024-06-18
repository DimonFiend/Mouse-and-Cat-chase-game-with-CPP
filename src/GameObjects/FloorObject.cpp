#include "FloorObject.h"
#include "Resources.h"

FloorObject::FloorObject(sf::Vector2f pos)
	: GameObject(Resources::Instance().getFloorTexture(), pos)
{}
