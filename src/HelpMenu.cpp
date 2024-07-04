#include "HelpMenu.h"
#include "Observer.h" 
#include <iostream>
#include "Configs.h"

HelpMenu::HelpMenu(Observer* observer)
{
	if (!m_texture.loadFromFile("Tutorial.png")) {
		std::cerr << "The tutorial.png didn't load proparly";
		system("pause");
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	m_observer = observer;
	setView();
	setBackgroundScale();
}

void HelpMenu::setView()
{
	auto widthBound = m_sprite.getGlobalBounds().width;
	auto heightBound = m_sprite.getGlobalBounds().height;

	float scaleX = W_WIDTH / widthBound;
	float scaleY = W_HEIGHT / heightBound;
	float scale = std::min(scaleX, scaleY);

	m_view.setSize(W_WIDTH / scale, W_HEIGHT / scale);
	m_view.setCenter(widthBound / 2, heightBound / 2);
}

void HelpMenu::setBackgroundScale()
{
	sf::Vector2u textureSize = m_sprite.getTexture()->getSize();
	sf::Vector2f scale;
	scale.x = (float)W_WIDTH / textureSize.x;
	scale.y = (float)W_HEIGHT / textureSize.y;
	m_sprite.setScale(scale.x, scale.y);
}

void HelpMenu::render(sf::RenderWindow& window)
{
	window.setView(m_view);
	window.draw(m_sprite);
}

void HelpMenu::handleEvent(sf::RenderWindow& window)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type) {
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyPressed:
			m_observer->switchState("Main Menu");
			break;
		}
	}
}

void HelpMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}