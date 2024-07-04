#include "Controller.h"
#include "MainMenu.h"
#include "GameLevel.h"
#include "HelpMenu.h"
#include "EndGameMenu.h"
#include <iostream>



Controller::Controller(int w, int h, std::string title) {
    // Constructor implementation
    m_window.create(sf::VideoMode(w, h), title, sf::Style::Close);
	m_window.setFramerateLimit(60);
    m_currentState = std::move(std::make_unique<MainMenu>(this));
    run();
}

Controller::~Controller() {}

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
}

void Controller::processEvents() 
{
    for (auto event = sf::Event{};m_window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        m_currentState->handleEvent(event, m_window);
    }
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
		std::cout << "Game Over" << std::endl;
    }
    else if (buttonText == "EndGameMenu")
    {
        m_currentState = std::move(std::make_unique<EndGameMenu>(this));
    }

}
