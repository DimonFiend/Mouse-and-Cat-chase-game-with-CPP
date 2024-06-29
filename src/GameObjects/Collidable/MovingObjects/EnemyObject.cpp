#include "EnemyObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

EnemyObject::EnemyObject(float speed)
	: MovingObject(speed)
{

}

void EnemyObject::respawn()
{
	m_sprite.setPosition(MovingObject::getSpawn());
}