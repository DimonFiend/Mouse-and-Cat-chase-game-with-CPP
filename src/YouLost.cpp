#include "YouLost.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"
#include <iostream>

YouLost::YouLost(Observer* observer)
	: m_observer(observer), m_youLostMessage("No more lives :(, \nplease choose how you want to conitnue")
{
	m_buttons.push_back(Button("Restart", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 4))));
	m_buttons.push_back(Button("Exit", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 4) + 400)));
	Resources::instance().playMusic(Music::M_MainMenu);
	//set text for beat the game message
	m_Text.setFont(Resources::instance().getFont());
	m_Text.setString(m_youLostMessage);
	m_Text.setCharacterSize(48);
	m_Text.setFillColor(sf::Color::White);
}

YouLost::~YouLost()
{
	Resources::instance().stopMusic(Music::M_MainMenu);
}

void YouLost::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void YouLost::render(sf::RenderWindow& window)
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

void YouLost::handleEvent(sf::Event& event, sf::RenderWindow& window)
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
					if (button.getText() == "Restart") {
						m_observer->switchState("Start");
					}

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
		else if (event.key.code == sf::Keyboard::R)
		{
			m_observer->switchState("Start");
		}
		break;
	}
	}
	}
}
