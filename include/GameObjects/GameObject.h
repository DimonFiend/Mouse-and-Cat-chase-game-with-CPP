#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	virtual ~GameObject() = default;
	GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const { return m_sprite.getPosition();};
protected:
	sf::Sprite m_sprite;
private:
};