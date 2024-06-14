#pragma once
/*==================================================
* Button.h - Button class definition
* sets buttons for the game
==================================================*/
#include <SFML/Graphics.hpp>

class Button {

private:
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Font m_font;
	sf::Vector2f m_pos;

	void setText(std::string text);
	void setSprite(sf::Vector2f pos);
public:
	
	Button(std::string text, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	void setScale(float x, float y);
    sf::String getText() const;
};
