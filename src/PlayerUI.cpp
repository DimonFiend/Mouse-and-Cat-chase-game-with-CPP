#include "PlayerUI.h"
#include "Resources.h"
#include <format>
#include "Utilities.h"
#include "Configs.h"

PlayerUI::PlayerUI()
    : m_score(0), m_timeLeft({0,0}), m_health(0), m_keys(0),
    m_UIbar(Resources::instance().getUiBarTexture()),
    m_scoreText{ sf::Text(), sf::Text(), sf::Text(), sf::Text() }
{
    for (unsigned int i = 0; i < PlayerUI::Max; i++)
    {
        m_scoreText[i].setFont(Resources::instance().getFont());
        float characterSize = m_UIbar.getLocalBounds().width * 0.05;
        m_scoreText[i].setCharacterSize(static_cast<int>(characterSize));
    }
    setUIview();
}

// Set the position of the text elements
// needed inorder when text changes its size, it will not overlap with other text
void PlayerUI::setText()
{
    auto startPos = sf::Vector2f(20, GRID_SIZE / 5);

    for (unsigned int i = 0; i < PlayerUI::Max; i++)
    {
        auto bounds = m_scoreText[i].getLocalBounds();
        m_scoreText[i].setPosition(startPos.x, startPos.y);
        startPos.x += bounds.width + 20;
    }
}

void PlayerUI::setUIview()
{
    m_view.setSize(W_WIDTH, GRID_SIZE);
    m_view.setCenter(W_WIDTH / 2, GRID_SIZE / 2);
    m_view.setViewport(sf::FloatRect(0, 0, 1, 64.0f / W_HEIGHT));
    m_UIbar.setPosition({ 0 , 0 });
    m_UIbar.setScale(W_WIDTH / m_UIbar.getLocalBounds().width, GRID_SIZE / m_UIbar.getLocalBounds().height);
}

void PlayerUI::setScore(PosInt score)
{
    m_score = score;
    m_scoreText[UIElement::Score].setString(std::format("Score:{}", m_score));
}


void PlayerUI::setHealth(PosInt health)
{
    m_health = health;
    m_scoreText[UIElement::Health].setString(std::format("Health:{}", m_health));
 
}

void PlayerUI::setKey(PosInt key)
{
    m_keys = key;
    m_scoreText[UIElement::Key].setString(std::format("Keys:{}", m_keys));
}

void PlayerUI::setTimeLeft(float time)
{
    m_timeLeft = sf::Vector2i{ static_cast<int>(time) / 60, static_cast<int>(time) % 60 };

    m_scoreText[UIElement::TimeLeft].setString(std::format("Time Left:{:02}:{:02}", static_cast<int>(m_timeLeft.x), static_cast<int>(m_timeLeft.y)));

    timeCondition();
}


void PlayerUI::draw(sf::RenderWindow& window)
{
    setText();

	window.setView(m_view);
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
