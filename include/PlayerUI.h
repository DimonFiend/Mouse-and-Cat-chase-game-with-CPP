///=======================================================================
/// \file PlayerUI.h
/// \brief Header file for the PlayerUI class.
/// 
/// This class is responsible for displaying the player's health, score, time left, and keys.

#pragma once

#include <SFML/Graphics.hpp>
typedef unsigned int PosInt;

class PlayerUI {
public:
	PlayerUI();
	~PlayerUI() = default;

	// Setters
	void setScore(PosInt score);
	void setTimeLeft(float time);
	void setHealth(PosInt health);
	void setKey(PosInt key);

	void draw(sf::RenderWindow& window);

private:
	enum UIElement {
		Health,Key,
		Score,TimeLeft,
		PauseState,Max};

	unsigned int m_score;
	sf::Vector2i m_timeLeft;
	unsigned int m_health;
	unsigned int m_keys;

	sf::Text m_scoreText[PlayerUI::Max];
	sf::Sprite m_UIbar;
	sf::View m_view;

	// Private functions
	void timeCondition();
	void setUIview();
	void setText();
};