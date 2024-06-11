#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "GameState.h"

class Controller{

public:
	Controller(int w, int h, std::string title);
	~Controller();

	void run();
	void update();
	void render();
	void processEvents();


private:
	sf::RenderWindow window;
	std::unique_ptr<GameState> currentState;
};