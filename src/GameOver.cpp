#include "GameOver.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"
#include <iostream>

GameOver::GameOver(Observer* observer)
	: m_observer(observer), m_youLostMessage("No more lives :(, \nplease choose how you want to conitnue")
{
	m_buttons.push_back(Button("Restart", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2 - 200))));
	m_buttons.push_back(Button("Exit", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 4) + 200)));
	Resources::instance().playMusic(Music::M_MainMenu);
	//set text for beat the game message
	m_Text.setFont(Resources::instance().getFont());
	m_Text.setString(m_youLostMessage);
	m_Text.setCharacterSize(48);
	m_Text.setFillColor(sf::Color::White);
}

GameOver::~GameOver()
{
	Resources::instance().stopMusic(Music::M_MainMenu);
}

void GameOver::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void GameOver::render(sf::RenderWindow& window)
{
	sf::FloatRect textRect = m_Text.getLocalBounds();
	m_Text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top);

	// Set the position of the text to the center of the window
	m_Text.setPosition(window.getSize().x / 2.0f, 50.0f);
	window.draw(m_Text);

	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void GameOver::handleEvent(sf::RenderWindow& window)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
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
						handleClick(button);
					}
				}
			}
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::E)
			{
				window.close();
			}
			else if (event.key.code == sf::Keyboard::R)
			{
				m_observer->switchState("Start");
				return;
			}
			break;
		}
		}
	}
}

void GameOver::handleClick(const Button& check)
{
	if (check.getText() == "Restart") {
		m_observer->switchState("Start");
	}
	else
	{
		m_observer->switchState(check.getText());
	}
	return;
}