///=======================================================================
/// \file	HelpMenu.h
/// \brief	Header file for the HelpMenu class.
/// the HelpMenu class is a derived class from the GameState class.
/// It is responsible for the help menu of the game.

#pragma once
#include "GameState.h"


class Button;
class Observer;
class HelpMenu : public GameState {

public:
	HelpMenu() = delete;
	HelpMenu(Observer* observer);
	virtual ~HelpMenu() = default;
	virtual void render(sf::RenderWindow& window) const override;
	virtual void handleEvent(sf::RenderWindow& window) override;
	virtual void update(sf::Time deltaTime);

private:
	void setView();
	void setBackgroundScale();
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::View m_view;
	Observer* m_observer;
};