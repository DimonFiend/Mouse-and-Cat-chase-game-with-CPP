#pragma once
#include "GameState.h"
#include <vector>

class Button;
class Observer;
class EndGameMenu : public GameState {

public:
	EndGameMenu(Observer* observer);
	virtual ~EndGameMenu();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::RenderWindow& window) override;

private:
	std::vector<Button> m_button;
	Observer* m_observer;
	sf::Text m_Text;
	sf::Font m_Font;
	sf::View m_view;
	sf::RectangleShape m_textBackground;
	sf::Sprite m_background;

	void setText();
	void setBackground();
	void mouseClickHandle(sf::Event event, sf::RenderWindow& window);
	void keyboardHandle(sf::Event event, sf::RenderWindow& window);
};