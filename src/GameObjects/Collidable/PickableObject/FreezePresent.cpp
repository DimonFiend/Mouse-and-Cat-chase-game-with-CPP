#include "FreezePresent.h"
#include "MovingObject.h"

void FreezePresent::handleCollision(MovingObject& other)
{
	other.handleCollision(*this);
}

Objects FreezePresent::PresentId()
{
	return Present_Freeze;
}