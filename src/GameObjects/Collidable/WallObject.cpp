#include "WallObject.h"
#include "Resources.h"

WallObject::WallObject(sf::Vector2f pos) :
	CollidableObject(Resources::Instance().getWallTexture(), pos)
{

}

bool WallObject::doubleDispatch(GameObject* other)
{
	//return other->doubleDispatch(this);
	return true;
}