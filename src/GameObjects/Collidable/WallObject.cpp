#include "WallObject.h"
#include "Resources.h"

WallObject::WallObject(sf::Vector2f pos) :
	CollidableObject(Resources::instance().getWallTexture(), pos)
{

}

bool WallObject::doubleDispatch(CollidableObject* other)
{
	return other->doubleDispatch(this);
}