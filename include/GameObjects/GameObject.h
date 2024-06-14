#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject(const sf::Texture* const texture);
	virtual void draw(sf::RenderWindow& window) = 0;

private:
	sf::Sprite m_sprite;

};