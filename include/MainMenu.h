#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenu : public GameState {

public:
	MainMenu();
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event) override;

private:
	std::vector<Button> m_buttons;

};