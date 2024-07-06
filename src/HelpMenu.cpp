#include "HelpMenu.h"
#include "Observer.h" 
#include <iostream>
#include "Configs.h"
#include "Resources.h"

HelpMenu::HelpMenu(Observer* observer)
{
	m_sprite.setTexture(Resources::instance().getBackground(B_HelpMenu));
	m_sprite.setPosition(0, 0);
	m_observer = observer;
	setView();
	setBackgroundScale();
	setMusic(Resources::instance().getMusicPath(Music::M_MainMenu), true, MUSIC_VOLUME);
}

void HelpMenu::setView()
{
	m_view.setSize(W_WIDTH, W_HEIGHT);
	m_view.setCenter(W_WIDTH / 2, W_HEIGHT / 2);
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
		switch (event.type)
		{
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyReleased:
			m_observer->switchState("Main Menu");
			return;
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void HelpMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}