#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu()
{
	m_buttons.push_back(Button("Start", sf::Vector2f(400, 100)));
	m_buttons.push_back(Button("Help", sf::Vector2f(400, 300)));
	m_buttons.push_back(Button("Exit", sf::Vector2f(400, 500)));
}

void MainMenu::update()
{

}

void MainMenu::render(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void MainMenu::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			
		}
	}
}
