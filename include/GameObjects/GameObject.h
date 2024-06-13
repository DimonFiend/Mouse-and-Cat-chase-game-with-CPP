#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	GameObject(const sf::Texture* const texture);
	virtual void draw() = 0;

private:
	sf::Sprite m_sprite;

};