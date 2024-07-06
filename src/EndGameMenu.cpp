#include "EndGameMenu.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"
#include <iostream>

EndGameMenu::EndGameMenu(Observer* observer)
	: m_observer(observer), m_view(sf::FloatRect(0, 0, W_WIDTH, W_HEIGHT))
{
	m_button.push_back(Button("Main Menu", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2))));
	m_button.push_back(Button("Exit", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2 + 200))));

	setText();
	setBackground();
	setMusic(Resources::instance().getMusicPath(Music::M_GameFinish), false, MUSIC_VOLUME);
}

void EndGameMenu::setText()
{
	//set text for beat the game message

	m_Text.setFont(Resources::instance().getFont());
	m_Text.setString("Congradulations! you've beaten the game!");
	m_Text.setCharacterSize(48);
	m_Text.setFillColor(sf::Color::White);
	m_Text.setStyle(sf::Text::Bold);

	auto textSize = m_Text.getLocalBounds().getSize();
	m_Text.setOrigin({ textSize.x / 2, textSize.y / 2 });
	// Set the position of the text to the center of the window
	m_Text.setPosition(W_WIDTH / 2.0f, 50);
	m_view.setSize(W_WIDTH, W_HEIGHT);
	m_textBackground.setSize({ W_WIDTH, m_Text.getLocalBounds().height + 30 });
	m_textBackground.setFillColor(sf::Color::Black);
}

void EndGameMenu::setBackground()
{
	m_background.setTexture(Resources::instance().getBackground(Backgrounds::B_GameFinish));
	sf::Vector2u textureSize = m_background.getTexture()->getSize();
	sf::Vector2f scale;
	scale.x = (float)W_WIDTH / textureSize.x;
	scale.y = (float)W_HEIGHT / textureSize.y;
	m_background.setScale(scale.x, scale.y);
}

EndGameMenu::~EndGameMenu()
{

}

void EndGameMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void EndGameMenu::render(sf::RenderWindow& window)
{
	window.setView(m_view);
	window.draw(m_background);
	window.draw(m_textBackground);
	window.draw(m_Text);

	for (auto& button : m_button)
	{
		button.draw(window);
	}
}

void EndGameMenu::handleEvent(sf::RenderWindow& window)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonReleased:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mouseClickHandle(event, window);
			}
			break;
		}
		case sf::Event::KeyReleased:
		{
			keyboardHandle(event, window);
			break;
		}
		case sf::Event::Closed:
		{
			window.close();
			break;
		}
		}
	}
}

void EndGameMenu::mouseClickHandle(sf::Event event, sf::RenderWindow& window)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (auto& button : m_button)
		{
			if (button.isMouseOver(window))
			{
				m_observer->switchState(button.getText());
				return;
			}
		}
	}
}

void EndGameMenu::keyboardHandle(sf::Event event, sf::RenderWindow& window)
{
	if (event.key.code == sf::Keyboard::E)
	{
		window.close();
	}
	else if (event.key.code == sf::Keyboard::M)
	{
		m_observer->switchState("Main Menu");
		return;
	}
}