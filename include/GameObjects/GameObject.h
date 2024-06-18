#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject(const sf::Texture& texture, sf::Vector2f pos);
	virtual void draw(sf::RenderWindow& window) const;
	void move(sf::Vector2f direction, float speed, sf::Time deltaTime);

private:
	sf::Sprite m_sprite;
};