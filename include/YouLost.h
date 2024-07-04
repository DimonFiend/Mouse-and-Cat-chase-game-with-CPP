#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class YouLost : public GameState {

public:
	YouLost(Observer* observer);
	virtual ~YouLost();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;

private:
	std::vector<Button> m_buttons;
	Observer* m_observer;
	sf::Text m_Text;
	sf::Font m_Font;
	std::string m_youLostMessage;
};