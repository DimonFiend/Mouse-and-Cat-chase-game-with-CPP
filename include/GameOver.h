#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class GameOver : public GameState {

public:
	GameOver(Observer* observer);
	virtual ~GameOver();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	Observer* m_observer;
	sf::Text m_Text;
	sf::Font m_Font;
	std::string m_youLostMessage;

	void handleClick(const Button& check);
};