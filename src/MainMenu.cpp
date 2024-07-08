#include "MainMenu.h"
#include "Observer.h"
#include "Button.h"
#include "Configs.h"
#include "Resources.h"

MainMenu::MainMenu(Observer* observer)
	: m_observer(observer), m_view(sf::FloatRect(0, 0, W_WIDTH, W_HEIGHT))
{
	m_background.setTexture(Resources::instance().getBackground(B_MainMenu));
	this->setBackgroundScale();
	m_buttons.push_back(Button("Start", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 1.5))));
	m_buttons.push_back(Button("Help", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 1.5) + 100)));
	m_buttons.push_back(Button("Exit", sf::Vector2f(W_WIDTH /2, (W_HEIGHT / 1.5) + 200)));

	setMusic(Resources::instance().getMusicPath(Music::M_MainMenu), true, MUSIC_VOLUME);
}

void MainMenu::setBackgroundScale()
{
	sf::Vector2u textureSize = m_background.getTexture()->getSize();
	sf::Vector2f scale;
	scale.x = (float)W_WIDTH / textureSize.x;
	scale.y = (float)W_HEIGHT / textureSize.y;
	m_background.setScale(scale.x, scale.y);
}

void MainMenu::update(sf::Time deltaTime)
{
	(void)deltaTime;
}

void MainMenu::render(sf::RenderWindow& window) const
{
	window.setView(m_view);
	window.draw(m_background);
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}

void MainMenu::handleEvent(sf::RenderWindow& window)
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
                        m_observer->switchState(button.getText());
                        return;
                    }
                }
            }
            break;
        }
        case sf::Event::KeyReleased:
        {
            if (event.key.code == sf::Keyboard::E)
            {
                window.close();
            }
            else if (event.key.code == sf::Keyboard::H )
            {
                m_observer->switchState("Help");
                return;
            }
            else if (event.key.code == sf::Keyboard::S)
            {
                m_observer->switchState("Start");
                return;
            }
            break;
        }
		case sf::Event::Closed:
		{
			window.close();
		}
        }
    }
}