#include "GameOver.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"
#include <iostream>

GameOver::GameOver(Observer* observer)
	: m_observer(observer)
{
	m_buttons.push_back(Button("Restart", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2))));
	m_buttons.push_back(Button("Main Menu", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2 + 150 ))));
	m_buttons.push_back(Button("Exit", sf::Vector2f(W_WIDTH / 2, (W_HEIGHT / 2) + 300)));
	m_view.setSize(W_WIDTH, W_HEIGHT);
	m_background.setTexture(Resources::instance().getBackground(Backgrounds::B_GameOver));
	setBackgroundScale();
	setText();
	setMusic(Resources::instance().getMusicPath(Music::M_GameOver), false, MUSIC_VOLUME);
}

void GameOver::setText()
{
	m_Text.setFont(Resources::instance().getFont());
	m_Text.setString("Game Over! no more lives left!");
	m_Text.setCharacterSize(48);
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);
	auto textSize = m_Text.getLocalBounds().getSize();
	m_Text.setOrigin({ textSize.x / 2, textSize.y / 2 });
	m_Text.setPosition(W_WIDTH / 2.0f, 50);

	m_textBackground.setSize({ m_Text.getLocalBounds().width + 20, m_Text.getLocalBounds().height + 30 });
	m_textBackground.setFillColor(sf::Color::Blue);
	m_textBackground.setOrigin(m_textBackground.getSize().x / 2, m_textBackground.getSize().y / 2);
	m_textBackground.setPosition(m_Text.getPosition());
}

void GameOver::setBackgroundScale()
{
	sf::Vector2u textureSize = m_background.getTexture()->getSize();
	sf::Vector2f scale;
	scale.x = (float)W_WIDTH / textureSize.x;
	scale.y = (float)W_HEIGHT / textureSize.y;
	m_background.setScale(scale.x, scale.y);
}

void GameOver::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void GameOver::render(sf::RenderWindow& window) const
{
	window.setView(m_view);
	window.draw(m_background);
	window.draw(m_textBackground);
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
			mouseClickHandle(event, window);
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
		}
		}
	}
}

void GameOver::mouseClickHandle(sf::Event event, sf::RenderWindow& window)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (auto& button : m_buttons)
		{
			if (button.isMouseOver(window))
			{
				m_observer->switchState(button.getText());
				return;
			}
		}
	}
}

void GameOver::keyboardHandle(sf::Event event, sf::RenderWindow& window)
{
	if (event.key.code == sf::Keyboard::E)
	{
		window.close();
	}
	else if (event.key.code == sf::Keyboard::R)
	{
		m_observer->switchState("Restart");
		return;
	}
	else if (event.key.code == sf::Keyboard::M)
	{
		m_observer->switchState("Main Menu");
		return;
	}
}