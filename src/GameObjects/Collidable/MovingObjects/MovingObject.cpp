#include "MovingObject.h"

MovingObject::MovingObject(float speed, sf::Vector2f pos, sf::IntRect obj)
	:CollidableObject(pos, obj), m_speed(speed), m_direction(Idle)
{
	setSpawn(m_sprite.getPosition());
	setLastPos(m_sprite.getPosition());
	setAnimator();
}

MovingObject& MovingObject::operator=(MovingObject& other)
{
	setSpawn(other.getSpawn());
	setLastPos(other.getLastPos());
	setAnimator();
	return *this;
}

//returns the direction vector by enum value
sf::Vector2f MovingObject::enumToVector() const
{
	switch (m_direction)
	{
	case Up:
		return sf::Vector2f(0, -1);
	case Down:
		return sf::Vector2f(0, 1);
	case Left:
		return sf::Vector2f(-1, 0);
	case Right:
		return sf::Vector2f(1, 0);
	}
	return sf::Vector2f(0, 0);
}

//returns the enum value by direction vector
Direction MovingObject::vectorToEnum(const sf::Vector2i& pos) const
{
	if (pos.x == 0 && pos.y == -1) {return Up;}
	if (pos.x == 0 && pos.y == 1) {return Down;}
	if (pos.x == -1 && pos.y == 0) {return Left;}
	if (pos.x == 1 && pos.y == 0) {return Right;}
	return Idle;
}

//returns the grid index of the given position
sf::Vector2i MovingObject::toGridIndex(const sf::Vector2f& position) const
{
	return sf::Vector2i(static_cast<int>(position.x) / GRID_SIZE, static_cast<int>(position.y) / GRID_SIZE);
}

void MovingObject::setAnimator()
{
	m_animator = std::move(std::make_unique<Animator>(m_sprite));
}
void MovingObject::Animate(sf::Time deltaTime, Direction direction) const
{
	m_animator->update(deltaTime, direction);
}