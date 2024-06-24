#include "DestroyPresent.h"
#include "MovingObject.h"

void DestroyPresent::handleCollision(MovingObject& other)
{
	other.handleCollision(*this);
}

Objects DestroyPresent::PresentId()
{
	return Present_CatDestr;
}