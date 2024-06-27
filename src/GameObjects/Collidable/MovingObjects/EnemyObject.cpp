#include "EnemyObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

EnemyObject::EnemyObject(float speed)
	: MovingObject(speed)
{

}

void EnemyObject::handleCollision(CollidableObject& other)
{
	//other.handleCollision(*this);
}

void EnemyObject::handleCollision(DoorObject& other)
{
	m_sprite.setPosition(MovingObject::getLastPos());
}
/*
void EnemyObject::handleCollision(TimePresent& other)
{
	other.handleCollision(*this);
}

void EnemyObject::handleCollision(FreezePresent& other)
{
	other.handleCollision(*this);
}

void EnemyObject::handleCollision(DestroyPresent& other)
{
	other.handleCollision(*this);
}
*/
void EnemyObject::handleCollision(CheeseObject& other)
{
}

void EnemyObject::handleCollision(KeyObject& other)
{
}

void EnemyObject::handleCollision(MousePlayer& other)
{
	other.handleCollision(*this);
}
