#include "PlayerUI.h"
#include "Resources.h"
#include <format>
#include "Utilities.h"

PlayerUI::PlayerUI(sf::View windowSize)
    : m_score(0), m_timeLeft({0,0}), m_health(0), m_keys(0),
    m_UIbar(Resources::instance().getUiBarTexture()),
    m_scoreText{ sf::Text(), sf::Text(), sf::Text(), sf::Text() }
{
    for (unsigned int i = 0; i < PlayerUI::Max; i++)
    {
        m_scoreText[i].setFont(Resources::instance().getFont());
        m_scoreText[i].setCharacterSize(32);
        m_scoreText[i].setFillColor(sf::Color::White);
    }

	auto windowArea = windowSize.getViewport();

    m_UIbar.setPosition({ 0 , 0});

    // Calculate the scale factors
    float xFactor = windowSize.getSize().x / static_cast<float>(m_UIbar.getTexture()->getSize().x);
    float yFactor = GRID_SIZE / static_cast<float>(m_UIbar.getTexture()->getSize().y);

    // Set the scale of the m_UIbar
    m_UIbar.setScale(xFactor, yFactor);

    // Update the position of the UI elements based on the scaled UI bar
    float elementXPosition = 0.0f;
    for (unsigned int i = 0; i < PlayerUI::Max; i++)
    {
        m_scoreText[i].setOrigin(m_scoreText[i].getGlobalBounds().width / 2, m_scoreText[i].getGlobalBounds().height / 2);
        m_scoreText[i].setPosition(elementXPosition, m_UIbar.getGlobalBounds().height / 2);
        elementXPosition += m_scoreText[i].getGlobalBounds().width + 100;
    }
}

void PlayerUI::setScore(PosInt score)
{
    m_score = score;
    m_scoreText[UIElement::Score].setString(std::format("Score: {}", m_score));
}


void PlayerUI::setHealth(PosInt health)
{
    m_health = health;
    m_scoreText[UIElement::Health].setString(std::format("Health: {}", m_health));
 
}

void PlayerUI::setKey(PosInt key)
{
    m_keys = key;
    m_scoreText[UIElement::Key].setString(std::format("Keys: {}", m_keys));
}

void PlayerUI::setTimeLeft(float time)
{
    m_timeLeft = sf::Vector2i{ static_cast<int>(time) / 60, static_cast<int>(time) % 60 };

    m_scoreText[UIElement::TimeLeft].setString(std::format("Time Left: {:02}:{:02}", static_cast<int>(m_timeLeft.x), static_cast<int>(m_timeLeft.y)));

    timeCondition();
}

void PlayerUI::draw(sf::RenderWindow& window)
{
    window.draw(m_UIbar);
    for (unsigned int i = 0; i < PlayerUI::Max; i++)
    {
        window.draw(m_scoreText[i]);
    }
}

void PlayerUI::timeCondition()
{
    if (m_timeLeft.x == 0 && m_timeLeft.y <= 30)
    {
        m_scoreText[UIElement::TimeLeft].setFillColor(sf::Color::Red);
    }
    else
    {
        m_scoreText[UIElement::TimeLeft].setFillColor(sf::Color::White);
    }
}
