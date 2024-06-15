#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject(const sf::Texture* const texture, sf::Vector2f pos);
	virtual void draw(sf::RenderWindow& window) const;

private:
	sf::Sprite m_sprite;

};