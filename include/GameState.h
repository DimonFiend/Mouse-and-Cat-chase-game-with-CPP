#pragma once

#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleEvent(sf::RenderWindow& window) = 0;
    virtual ~GameState() = default;
};
