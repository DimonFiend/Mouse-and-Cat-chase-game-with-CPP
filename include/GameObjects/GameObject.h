#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;
	sf::FloatRect getBounds() const;
protected:
	sf::Sprite m_sprite;
private:
};