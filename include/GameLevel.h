#pragma once
#include "GameState.h"
#include <vector>
#include <memory>
#include "CollidableObject.h"
#include "EnemyObject.h"
#include "MousePlayer.h"
#include "LevelLoader.h"

class Observer;
class GameLevel : public GameState{

private:
	unsigned int m_levelNumber;
	Observer* m_observer;
	std::unique_ptr<LevelLoader> m_level;
	sf::Vector2f m_mapSize;
	sf::View m_view;

	std::unique_ptr<MousePlayer> m_player;
	std::vector<std::unique_ptr<EnemyObject>> m_enemys;
	std::vector<std::unique_ptr<CollidableObject>> m_collidableObjects;
	std::vector<std::unique_ptr<GameObject>> m_staticObjects;

	void checkCollision();
	void removePickable();
	void setView();
	void move(sf::Time deltaTime);
public:
	GameLevel(Observer* observer);
	void setMapSize(const sf::Vector2f mapSize);
	virtual ~GameLevel() = default;
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

	void setPlayer(std::unique_ptr<MousePlayer> player);
	void setEnemy(std::unique_ptr<EnemyObject> enemy);
	void setCollidable(std::unique_ptr<CollidableObject> collidable);
	void setStatic(std::unique_ptr<GameObject> object);
	size_t getEnemyCount() const;

};