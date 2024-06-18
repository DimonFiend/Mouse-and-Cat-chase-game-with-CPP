#include "MainMenu.h"
#include "Observer.h"


MainMenu::MainMenu(Observer* observer)
	: m_observer(observer)
{
	m_buttons.push_back(Button("Start", sf::Vector2f(400, 100)));
	m_buttons.push_back(Button("Help", sf::Vector2f(400, 300)));
	m_buttons.push_back(Button("Exit", sf::Vector2f(400, 500)));
}

void MainMenu::update(sf::Time deltaTime)
{

}

void MainMenu::render(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void MainMenu::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (auto& button : m_buttons)
			{
				if (button.isMouseOver(window))
				{
					m_observer->switchState(button.getText());
				}
			}
		}
	}
	}
}
