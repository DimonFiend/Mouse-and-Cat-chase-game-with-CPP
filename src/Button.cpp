#include "Button.h"
#include "Resources.h"

#include <iostream>
Button::Button(std::string text, sf::Vector2f pos)
{
	setSprite(pos);
	setText(text);
}

void Button::setSprite(sf::Vector2f pos)
{

	m_sprite.setTexture(Resources::instance().getButtonTexture());

	
	//sets the origin of the sprite to the center and scales it
	sf::Vector2f buttonSize = m_sprite.getLocalBounds().getSize();
	m_sprite.setOrigin(buttonSize.x / 2.f, buttonSize.y / 2.f);
	m_sprite.setPosition(pos);
	setScale(5.f, 1.5f);

}

void Button::setText(std::string text)
{
	m_firstLetter.setFont(Resources::instance().getFont());
	m_firstLetter.setString(text[0]);
	m_firstLetter.setCharacterSize(48);
	m_firstLetter.setFillColor(sf::Color::White);
	m_firstLetter.setStyle(sf::Text::Bold | sf::Text::Underlined);

	m_text.setFont(Resources::instance().getFont());
	m_text.setString(text);
	m_text.setCharacterSize(48);
	m_text.setFillColor(sf::Color::White);

	// Get the local bounds of the text and set its origin to the center
	sf::FloatRect textBounds = m_text.getLocalBounds();
	m_text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
	m_text.setPosition(m_sprite.getPosition());

	m_firstLetter.setPosition(m_text.findCharacterPos(0));
}
void Button::setScale(float x, float y)
{
	m_sprite.setScale(x, y);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
	window.draw(m_firstLetter);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	sf::Vector2f mouse_pos{ window.mapPixelToCoords(sf::Mouse::getPosition(window)) };

	if (m_sprite.getGlobalBounds().contains(mouse_pos))
	{
		return true;
	}

	return false;
}

sf::String Button::getText() const
{
	return m_text.getString();
}