#include "EndGameMenu.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"
#include <iostream>

EndGameMenu::EndGameMenu(Observer* observer)
	: m_observer(observer)
{
	m_button = Button("Main Menu", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2 - 100)));
	Resources::instance().playMusic(Music::M_GameFinish);
	//set text for beat the game message
	m_Text.setFont(Resources::instance().getFont());
	m_Text.setString("Congradulations! you've beat the game!");
	m_Text.setCharacterSize(48);
	m_Text.setFillColor(sf::Color::White);

	auto textSize = m_Text.getLocalBounds().getSize();
	m_Text.setOrigin({ textSize.x / 2, textSize.y / 2 });

	// Set the position of the text to the center of the window
	m_Text.setPosition(W_WIDTH / 2.0f, 30);
	
}

EndGameMenu::~EndGameMenu()
{
	Resources::instance().stopMusic(Music::M_GameFinish);
}

void EndGameMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void EndGameMenu::render(sf::RenderWindow& window)
{
	window.draw(m_Text);

	m_button.draw(window);
}

void EndGameMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_button.isMouseOver(window))
			{
				m_observer->switchState(m_button.getText());
			}
		}
		break;

	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::M)
		{
			m_observer->switchState("Start");
		}
	}
	}
	}
}
