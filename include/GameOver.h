///=======================================================================
/// \file    GameOver.h
/// \brief   Header file for the GameOver class.
/// the GameOver class is a derived class from the GameState class.
/// It is responsible for the game over screen of the game.

#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class GameOver : public GameState {

public:
	GameOver(Observer* observer);
	virtual ~GameOver() = default;
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) const override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	Observer* m_observer;
	sf::RectangleShape m_textBackground;
	sf::Text m_Text;
	sf::View m_view;
	sf::Sprite m_background;

	void mouseClickHandle(sf::Event event, sf::RenderWindow& window);
	void keyboardHandle(sf::Event event, sf::RenderWindow& window);
	void setBackgroundScale();
	void setText();
};