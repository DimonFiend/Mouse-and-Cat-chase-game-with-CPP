#include "DestroyPresent.h"
#include "CollidableObject.h"

void DestroyPresent::handleCollision(CollidableObject& other)
{
	//other.handleCollision(*this);
}

Objects DestroyPresent::PresentId()
{
	return Present_CatDestr;
}