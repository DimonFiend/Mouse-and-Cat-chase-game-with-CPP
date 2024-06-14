#pragma once
#include "GameState.h"
#include <vector>
#include <memory>

class Observer;
/*
class MovingObject;
class CollidableObject;
class StaticObject;
*/
class GameLevel : public GameState{

private:
	Observer* m_observer;
	//std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	//std::vector<std::unique_ptr<CollidableObject>> m_collidableObjects;
	//std::vector<std::unique_ptr<StaticObject>> m_staticObjects;

public:
	GameLevel(Observer* observer);

	virtual ~GameLevel() = default;

	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;


};