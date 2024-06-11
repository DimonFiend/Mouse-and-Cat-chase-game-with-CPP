#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "GameState.h"
#include "Observer.h"

class Controller : public Observer{

public:
	Controller(int w, int h, std::string title);
	~Controller();

	void run();
	void update();
	void render();
	void processEvents();

	virtual void switchState(const std::string& buttonText) override;

private:
	sf::RenderWindow m_window;
	std::unique_ptr<GameState> m_currentState;
};