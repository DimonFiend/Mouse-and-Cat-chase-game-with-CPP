///=======================================================================
/// \file    EndGameMenu.h
/// \brief   Header file for the EndGameMenu class.
/// the EndGameMenu class is a derived class from the GameState class.
/// It is responsible for the end game screen of the game.

#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class EndGameMenu : public GameState {

public:
	EndGameMenu(Observer* observer);
	virtual ~EndGameMenu() = default;
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) const override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_button;
	Observer* m_observer;
	sf::Text m_Text;
	sf::Font m_Font;
	sf::View m_view;
	sf::RectangleShape m_textBackground;
	sf::Sprite m_background;

	//private functions
	void setText();
	void setBackground();
	void mouseClickHandle(sf::Event event, sf::RenderWindow& window);
	void keyboardHandle(sf::Event event, sf::RenderWindow& window);
};