#pragma once

#include <SFML/Graphics.hpp>
typedef unsigned int PosInt;

class PlayerUI {
public:
	PlayerUI(sf::View WindowSize);
	~PlayerUI() = default;

	void setScore(PosInt score);
	void setTimeLeft(float time);
	void draw(sf::RenderWindow& window);
	void setHealth(PosInt health);
	void setKey(PosInt key);
	void setUIscale(float scale) { m_UIbar.setScale(1, scale); }
	float getUiWidth() const {return m_UIbar.getGlobalBounds().width; }
	float getUiheight() const {return m_UIbar.getGlobalBounds().height; }
private:
	enum UIElement {
		Health,
		Key,
		Score,
		TimeLeft,
		Max
	};
	unsigned int m_score;
	sf::Vector2i m_timeLeft;
	unsigned int m_health;
	unsigned int m_keys;
	sf::Text m_scoreText[PlayerUI::Max];
	sf::Sprite m_UIbar;

	void timeCondition();
};