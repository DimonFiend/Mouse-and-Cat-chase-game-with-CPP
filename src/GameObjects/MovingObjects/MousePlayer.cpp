#include "MousePlayer.h"
#include "Resources.h"

MousePlayer::MousePlayer(sf::Vector2f pos)
	: MovingObject(Resources::Instance().getMouseTexture(), pos)
{

}

void MousePlayer::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	GameObject::move(movement,MovingObject::getSpeed(), deltaTime);

}

sf::Vector2f MousePlayer::getDirection() const
{
	sf::Vector2f movement(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += 1;
	}

	return movement;
}