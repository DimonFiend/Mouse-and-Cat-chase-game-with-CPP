#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject(const sf::Texture& texture, sf::Vector2f pos);
	virtual void draw(sf::RenderWindow& window) const;
	sf::Sprite& getSprite();
	void setTextureRect(sf::IntRect rect);
private:
	sf::Sprite m_sprite;
};