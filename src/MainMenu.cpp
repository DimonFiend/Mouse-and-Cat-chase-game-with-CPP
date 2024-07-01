#include "MainMenu.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"

MainMenu::MainMenu(Observer* observer)
	: m_observer(observer)
{
	m_buttons.push_back(Button("Start", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 4))));
	m_buttons.push_back(Button("Help", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 4) + 200)));
	m_buttons.push_back(Button("Exit", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 4) + 400)));
}

void MainMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void MainMenu::render(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void MainMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
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
		break;
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::E)
		{
			window.close();
		}
		else if (event.key.code == sf::Keyboard::H)
		{
			m_observer->switchState("Help");
		}
		else if (event.key.code == sf::Keyboard::S)
		{
			m_observer->switchState("Start");
		}
		break;
	}
	}
	}
}
