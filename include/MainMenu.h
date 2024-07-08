///=======================================================================
/// \file	MainMenu.h
/// \brief	Header file for the MainMenu class.
/// the MainMenu class is a derived class from the GameState class.
/// It is responsible for the main menu of the game.

#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class MainMenu : public GameState {

public:
	MainMenu(Observer* observer);
	virtual ~MainMenu() = default;
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) const override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	sf::Sprite m_background;
	sf::View m_view;
	Observer* m_observer;
	void setBackgroundScale();
};