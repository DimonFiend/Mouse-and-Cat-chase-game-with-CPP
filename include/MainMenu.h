#pragma once
#include "GameState.h"
#include "Button.h"
class Observer;
class MainMenu : public GameState {

public:
	MainMenu(Observer* observer);
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	Observer* m_observer;
};