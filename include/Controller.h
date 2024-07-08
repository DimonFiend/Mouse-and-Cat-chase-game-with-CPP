///=======================================================================
/// \file    Controller.h
/// \brief   Header file for the Controller class.
/// the Controller class is responsible for the game loop and the game windows.


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
	void update(sf::Time deltaTime);
	void render();
	void processEvents();

	virtual void switchState(const std::string& buttonText) override; // switch between game states
	static void startGame(); // static function to run the game
private:
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	std::unique_ptr<GameState> m_currentState;
	sf::View m_view;
};