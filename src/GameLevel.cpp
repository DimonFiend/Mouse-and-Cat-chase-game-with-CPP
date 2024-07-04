#include "GameLevel.h"
#include "Observer.h"
#include "Resources.h"
#include "MousePlayer.h"
#include "ObjectsInclude.h"
#include "FloorObject.h"
#include "Configs.h"
#include <iostream>

GameLevel::GameLevel(Observer* observer) :
	m_observer(observer),
	m_levelNumber(1),
	m_level(std::make_unique<LevelLoader>(this, m_levelNumber)),
	m_isPaused(false)
{
	LoadLevel();
	Resources::instance().playMusic(Music::M_GameLevel);
}

GameLevel::~GameLevel()
{
	Resources::instance().stopMusic(Music::M_GameLevel);
	m_level.reset();
}

void GameLevel::update(sf::Time deltaTime)
{
	if (!m_isPaused)
	{
		this->move(deltaTime);
		this->checkCollision();
		this->removePickable();
		this->updateTimer();
	}

	checkConditions();
}

void GameLevel::updateTimer()
{
	m_timeLeft = m_timerStart - m_time.getElapsedTime().asSeconds();
}

void GameLevel::removePickable()
{
	std::erase_if(m_collidableObjects, [](auto& collidable)
		{return collidable->getToDelete();});
}
void GameLevel::render(sf::RenderWindow& window)
{
	window.setView(m_view);

	for (auto& staticObject : m_staticObjects)
	{
		staticObject->draw(window);
	}

	for (auto& collidableObject : m_collidableObjects)
	{
		collidableObject->draw(window);
	}

	for (auto& enemyObject : m_enemys)
	{
		enemyObject->draw(window);
	}

	m_player->draw(window);

}

void GameLevel::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	if (event.Closed)
	{
		window.close();
	}
	else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	{
		m_isPaused = !m_isPaused; // Toggle the pause state
	}
}

void GameLevel::checkConditions()
{
	if (m_player->getLives() == 0)
	{
		m_observer->switchState("GameOver");
	}
	else if (CheeseObject::getCheeseCount() == 0)
	{
		m_levelNumber++;
		this->LoadLevel();
	}
	else if (m_timeLeft <= 0)
	{
		m_observer->switchState("GameOver");
		this->LoadLevel();
	}
	
}

void GameLevel::LoadLevel()
{
	m_collidableObjects.clear();
	m_staticObjects.clear();
	m_enemys.clear();
	m_level = std::make_unique<LevelLoader>(this, m_levelNumber);
	m_level->loadLevel();

	if (m_level->filesFinished())
	{
		this->endOfLevels();
		return;
	}

	this->setTimer();
}

void GameLevel::respawn()
{
	m_player->respawn();

	for (auto& enemy : m_enemys)
	{
		enemy->respawn();
	}
}

void GameLevel::move(sf::Time deltaTime)
{
	m_player->move(deltaTime);
	for (auto& enemy : m_enemys)
	{
		enemy->move(deltaTime, this);
	}
}

void GameLevel::checkCollision()
{

	this->checkObjectsCollision(m_player.get());

	for (auto& enemy : m_enemys)
	{
		this->checkObjectsCollision(enemy.get());
		this->checkMovingCollision(enemy.get());	
	}

	this->checkMovingCollision(m_player.get());
}

void GameLevel::checkMovingCollision(CollidableObject* obj)
{
	for (auto& enemys : m_enemys)
	{
		if (obj->checkCollision(*enemys))
		{
			obj->handleCollision(*enemys);
		}
	}
}

void GameLevel::checkObjectsCollision(CollidableObject* obj)
{
	for (auto& collidableObject : m_collidableObjects)
	{
		if (collidableObject->checkCollision(*obj))
		{
			collidableObject->handleCollision(*obj);
		}
	}
}

// calculates the nearest paths to the object position by grid index
MovablePath GameLevel::getPath(const sf::Vector2i pos) const
{
    MovablePath path;

    for (auto& floor : m_staticObjects)
    {
        sf::Vector2f floorPos = floor->getPosition();
		int xIndex = static_cast<int>(std::floor(floorPos.x / 64));
		int yIndex = static_cast<int>(std::floor(floorPos.y / 64));

        if ((std::abs(xIndex-pos.x) == 1 && std::abs(yIndex-pos.y) == 0)
			|| std::abs(yIndex-pos.y) == 1 && std::abs(xIndex-pos.x) == 0)
        {
			path.push_back(sf::Vector2i{xIndex, yIndex});
        }
    }
    return path;
}

sf::Vector2f GameLevel::getPlayerPosition() const
{
	return m_player->getPosition();
}

void GameLevel::setMapSize(const sf::Vector2f mapSize)
{
	m_mapSize = mapSize;
	this->setView();
}

/*set the window view to fit the level size*/
void GameLevel::setView()
{
	float scaleX = W_WIDTH / m_mapSize.x;
	float scaleY = W_HEIGHT / m_mapSize.y;
	float scale = std::min(scaleX, scaleY);

	m_view.setSize(W_WIDTH / scale, W_HEIGHT / scale);
	m_view.setCenter(m_mapSize.x / 2, m_mapSize.y / 2);
}

/*=========================Level-Setters============================================*/
void GameLevel::setPlayer(std::unique_ptr<MousePlayer> player)
{
	m_player = std::move(player);
}
void GameLevel::setEnemy(std::unique_ptr<EnemyObject> enemy)
{
	m_enemys.push_back(std::move(enemy));
}
void GameLevel::setCollidable(std::unique_ptr<CollidableObject> collidable)
{
	m_collidableObjects.push_back(std::move(collidable));
}
void GameLevel::setStatic(std::unique_ptr<GameObject> object)
{
	m_staticObjects.push_back(std::move(object));
}
/*================================================================================*/
void GameLevel::setTimer()
{
	m_timerStart += (CheeseObject::getCheeseCount()) * 5.f;

	if (auto enemyCount = getEnemyCount(); enemyCount > 0)
	{
		m_timerStart += (m_enemys.size()) * 30.f;
	}
}

size_t GameLevel::getEnemyCount() const
{
    return m_enemys.size();
}

sf::Vector2f GameLevel::getTime() const
{
	int minutes = static_cast<int>(m_timeLeft) / 60;
	int seconds = static_cast<int>(m_timeLeft) % 60;
	return sf::Vector2f(minutes, seconds);
}

void GameLevel::destroyEnemie()
{
	int enemyCount = getEnemyCount();
	if (enemyCount > 1)
	{
		int index = rand() % enemyCount;
		m_enemys.erase(m_enemys.begin() + index);
	}
}

void GameLevel::freezeEnemies()
{
	for (auto& enemy : m_enemys)
	{
		enemy->setFreeze();
	}
}

void GameLevel::addTime(float time)
{
	m_timeLeft += time;
}

//when all finished the last level - switch the state to EndGameMenu
void GameLevel::endOfLevels()
{
	m_observer->switchState("EndGameMenu");
}
