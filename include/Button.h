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
	sf::Text m_firstLetter;
	sf::Font m_font;
	sf::Vector2f m_pos;

	void setText(std::string text);
	void setSprite(sf::Vector2f pos);
public:
	Button() = default;
	Button(std::string text, sf::Vector2f pos);
	void draw(sf::RenderWindow& window) const;
	bool isMouseOver(sf::RenderWindow& window) const;
	void setScale(float x, float y);
    sf::String getText() const;
};
