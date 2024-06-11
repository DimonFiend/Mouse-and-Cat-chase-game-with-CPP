#include "Button.h"
#include "Resources.h"

Button::Button(std::string text, sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::Instance().getButtonTexture());

	sf::Vector2f buttonSize = m_sprite.getLocalBounds().getSize();
	sf::Vector2f buttonPosition(pos.x - buttonSize.x / 2, pos.y - buttonSize.y / 2);
	m_sprite.setPosition(buttonPosition);
	m_sprite.setScale(3.f, 1.f);

	m_text.setFont(Resources::Instance().getFont());
	m_text.setPosition(pos.x, pos.y-48);
	m_text.setString(text);
	m_text.setCharacterSize(48);
	m_text.setFillColor(sf::Color::Black);
	

}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}
