#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class MainMenu : public GameState {

public:
	MainMenu(Observer* observer);
	virtual ~MainMenu();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	sf::Sprite m_background;
	sf::View m_view;
	Observer* m_observer;

	void setBackgroundScale();
};