#pragma once
#include "GameState.h"

class Observer;
class GameLevel : public GameState{

private:


public:
	GameLevel(Observer* observer);
	~GameLevel();

	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;


};