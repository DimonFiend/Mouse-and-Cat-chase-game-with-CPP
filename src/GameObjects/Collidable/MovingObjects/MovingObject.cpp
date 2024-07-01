#include "MovingObject.h"

MovingObject::MovingObject(float speed, Direction dir)
	:m_speed(speed), m_direction(dir)
{}

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

Direction MovingObject::vectorToEnum(const sf::Vector2i& pos)
{
	if (pos.x == 0 && pos.y == -1) {return Up;}
	if (pos.x == 0 && pos.y == 1) {return Down;}
	if (pos.x == -1 && pos.y == 0) {return Left;}
	if (pos.x == 1 && pos.y == 0) {return Right;}
	return Idle;
}

sf::Vector2i MovingObject::toGridIndex(const sf::Vector2f& position) const
{
	return sf::Vector2i(static_cast<int>(position.x) / 64, static_cast<int>(position.y) / 64);
}

void MovingObject::setAnimator()
{
	m_animator = std::move(std::make_unique<Animator>(m_sprite));
}
void MovingObject::Animate(sf::Time deltaTime, Direction direction)
{
	m_animator->update(deltaTime, direction);
}