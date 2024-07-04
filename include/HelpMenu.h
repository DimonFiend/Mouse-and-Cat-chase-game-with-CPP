#pragma once
#include "GameState.h"


class Button;
class Observer;
class HelpMenu : public GameState {

public:
	HelpMenu() = delete;
	HelpMenu(Observer* observer);
	virtual void render(sf::RenderWindow& window) override;
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