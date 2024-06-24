#pragma once
#include "GameState.h"
#include <vector>
#include <memory>
#include "CollidableObject.h"
#include "EnemyObject.h"
#include "MousePlayer.h"

class LevelLoader;
class Observer;
class GameLevel : public GameState{

private:
	Observer* m_observer;
	LevelLoader* m_level;
	std::unique_ptr<MousePlayer> m_player;
	//std::vector<std::unique_ptr<EnemyObject>> m_enemys;
	std::vector<std::unique_ptr<CollidableObject>> m_collidableObjects;
	std::vector<std::unique_ptr<GameObject>> m_staticObjects;

	void removePickable();

public:
	GameLevel(Observer* observer);
	virtual ~GameLevel() = default;
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
};