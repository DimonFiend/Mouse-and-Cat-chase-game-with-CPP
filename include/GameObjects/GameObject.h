///======================================================================
/// \file GameObject.h
/// \brief Header file for the GameObject class.
/// the GameObject class is a base class for all the game objects in the game.

#pragma once
#include <SFML/Graphics.hpp>

class GameObject {

public:
	GameObject(sf::Vector2f pos, sf::IntRect obj);
	virtual ~GameObject() = default;
	GameObject& operator=(const GameObject& other) = default;
	virtual void draw(sf::RenderWindow& window) const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const { return m_sprite.getPosition();};
protected:
	sf::Sprite m_sprite;
private:
};