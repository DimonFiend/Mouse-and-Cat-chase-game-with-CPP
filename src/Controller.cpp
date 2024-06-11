#include "Controller.h"
#include "MainMenu.h"
//#include "HelpMenu.h"
//#include "GameLevel.h"



Controller::Controller(int w, int h, std::string title) {
    // Constructor implementation
    window.create(sf::VideoMode(w, h), title);
    currentState = std::make_unique<MainMenu>();
    run();
}

Controller::~Controller() {
    // Destructor implementation
}

void Controller::run() 
{
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Controller::update() {
    currentState->update();
}

void Controller::render() {
    window.clear();
    currentState->render(window);
    window.display();
}

void Controller::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        currentState->handleEvent(event);
    }
}
