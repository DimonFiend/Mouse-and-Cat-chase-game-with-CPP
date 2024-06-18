#include "MovingObject.h"

MovingObject::MovingObject(sf::Texture& texture, sf::Vector2f pos)
	: GameObject(texture, pos), m_speed(80)
{}