#include "MousePlayer.h"
#include "Resources.h"
#include "CheeseObject.h"
#include <iostream>
MousePlayer::MousePlayer(sf::Vector2f pos)
	: MovingObject(Resources::instance().getMouseTexture(), pos)
	, m_lives(3)
	, m_score(0)
	, m_moving(true)
{
	GameObject::setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void MousePlayer::move(sf::Time deltaTime)
{
	sf::Vector2f movement = getDirection();
	GameObject::getSprite().move(movement * MovingObject::getSpeed() * deltaTime.asSeconds());
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

void MousePlayer::handleCollision(CheeseObject& other)
{
	m_score += 10;
	other.setToDelete();
	std::cout << "Score: " << m_score << std::endl;
	//play eat sound
}

void MousePlayer::handleCollision(MovingObject& other)
{
	m_lives--;
	//other.handleCollision(*this);
	//respawn
	//play hit sound
}

bool MousePlayer::checkCollision(MovingObject& other)
{
	return getSprite().getGlobalBounds().intersects(other.getSprite().getGlobalBounds());
}