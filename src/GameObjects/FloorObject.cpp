#include "FloorObject.h"
#include "Resources.h"

FloorObject::FloorObject(sf::Vector2f pos)
	:GameObject(pos, Resources::instance().getTextureRect(Objects::Floor))
{}
