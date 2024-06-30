#include "EnemyObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

EnemyObject::EnemyObject(float speed, Direction dir)
	: MovingObject(speed, dir)
{

}

void EnemyObject::respawn()
{
	m_sprite.setPosition(MovingObject::getSpawn());
}

sf::Vector2f EnemyObject::calcRelativePos(sf::Vector2f pos) const
{
	auto loc_y = std::floor(pos.y / 64);
	auto loc_x = std::floor(pos.x / 64);

	auto pos_y = (pos.y) - loc_y * 64;
	auto pos_x = (pos.x) - loc_x * 64;

	return sf::Vector2f(pos_x, pos_y);
}