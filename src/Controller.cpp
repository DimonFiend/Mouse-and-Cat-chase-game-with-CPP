#include "Controller.h"
#include "MainMenu.h"
#include "GameLevel.h"
#include "HelpMenu.h"
#include "EndGameMenu.h"
#include "GameOver.h"
#include <iostream>
#include "Configs.h"


Controller::Controller(int w, int h, std::string title) {
    // Constructor implementation
    m_window.create(sf::VideoMode(w, h), title, sf::Style::Close);
	m_window.setFramerateLimit(60);
    m_currentState = std::move(std::make_unique<MainMenu>(this));
	m_view = m_window.getDefaultView();
}

Controller::~Controller() {}

void Controller::startGame()
{
    Controller controller(W_WIDTH,W_HEIGHT, "Mouse Run");
    controller.run();
}

void Controller::run() 
{

    while (m_window.isOpen()) 
    {
		auto deltaTime = m_clock.restart();
        render();
        processEvents();
        update(deltaTime);
    }
}

void Controller::update(sf::Time deltaTime) {
    m_currentState->update(deltaTime);
}

void Controller::render() {
    m_window.clear();
    m_currentState->render(m_window);
    m_window.display();
	m_window.setView(m_view);
}

void Controller::processEvents() 
{
    m_currentState->handleEvent(m_window);
}

void Controller::switchState(const std::string& buttonText)
{
	if (buttonText == "Start")
    {
		m_currentState = std::move(std::make_unique<GameLevel>(this));
	}
    else if (buttonText == "Help")
    {
		m_currentState = std::move(std::make_unique<HelpMenu>(this));
	}
    else if (buttonText == "Main Menu")
    {
        m_currentState = std::move(std::make_unique<MainMenu>(this));
    }
    else if (buttonText == "Exit")
    {
		m_window.close();
	}
    else if (buttonText == "GameOver")
    {
        m_currentState = std::move(std::make_unique<GameOver>(this));
    }
    else if (buttonText == "EndGameMenu")
    {
        m_currentState = std::move(std::make_unique<EndGameMenu>(this));
    }

}
