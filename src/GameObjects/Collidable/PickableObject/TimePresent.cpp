#include "TimePresent.h"
#include "MovingObject.h"

void TimePresent::handleCollision(MovingObject& other)
{
	other.handleCollision(*this);
}

Objects TimePresent::PresentId()
{
	return Present_Time;
}