#pragma once
#include "GameState.h"
#include <vector>
#include <memory>
#include "CollidableObject.h"
#include "EnemyObject.h"
#include "MousePlayer.h"
#include "LevelLoader.h"

typedef std::vector<sf::Vector2i> MovablePath;

class PlayerUI;
class Observer;
class GameLevel : public GameState {

private:
	unsigned int m_levelNumber;
	Observer* m_observer;
	sf::Clock m_time;
	float m_timerStart;
	float m_timeLeft;
	sf::Vector2f m_mapSize;
	sf::View m_view;
	sf::View m_backgroundView;
	sf::Sprite m_background;
	sf::Music m_music;
	bool m_isPaused;
	std::unique_ptr<PlayerUI> m_playerUI;

	std::unique_ptr<LevelLoader> m_level;
	std::unique_ptr<MousePlayer> m_player;
	std::vector<std::unique_ptr<EnemyObject>> m_enemys;
	std::vector<std::unique_ptr<CollidableObject>> m_collidableObjects;
	std::vector<std::unique_ptr<GameObject>> m_staticObjects;

	void LoadLevel();
	void checkConditions();
	void checkCollision();
	void checkObjectsCollision(CollidableObject* obj);
	void checkMovingCollision(CollidableObject* obj);
	void removePickable();
	void setView();
	void move(sf::Time deltaTime);
	void updateTimer();
	void setBackground();
	void setUI();
	void pause();
	void levelFinishScore();
public:
	GameLevel(Observer* observer);
	void setMapSize(const sf::Vector2f mapSize);
	virtual ~GameLevel();
	virtual void update(sf::Time deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void handleEvent(sf::RenderWindow& window) override;

	void respawn();
	void destroyEnemie();
	void freezeEnemies();
	void setPlayer(std::unique_ptr<MousePlayer>& player);
	void setEnemy(std::unique_ptr<EnemyObject> enemy);
	void setCollidable(std::unique_ptr<CollidableObject> collidable);
	void setStatic(std::unique_ptr<GameObject> object);
	void setTimer();
	sf::Vector2f getMapSize() const { return m_mapSize; };
	sf::Vector2f getPlayerPosition() const;
	size_t getEnemyCount() const;
	MovablePath getPath(const sf::Vector2i pos) const;
	sf::Vector2f getTime() const;
	void addTime(float time);
	void endOfLevels();
};