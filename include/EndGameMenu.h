#pragma once
#include "GameState.h"
#include <vector>
#include "Button.h"

class Observer;
class EndGameMenu : public GameState {

public:
	EndGameMenu(Observer* observer);
	virtual ~EndGameMenu();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	Button m_button;
	Observer* m_observer;
	sf::Text m_Text;
	sf::Font m_Font;
};