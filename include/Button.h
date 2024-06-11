#pragma once

#include <SFML/Graphics.hpp>

class Button {

private:
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Font m_font;
	sf::Vector2f m_pos;

public:
	
	Button(std::string text, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);
	bool isMouseOver(sf::RenderWindow& window);
	void setScale(float x, float y);
};
