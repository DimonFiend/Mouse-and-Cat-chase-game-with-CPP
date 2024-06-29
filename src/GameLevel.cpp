#include "GameLevel.h"
#include "Observer.h"
#include "Resources.h"
#include "MousePlayer.h"
#include "ObjectsInclude.h"
#include "FloorObject.h"
#include <iostream>

GameLevel::GameLevel(Observer* observer) :
	m_observer(observer),
	m_levelNumber(1),
	m_level(std::make_unique<LevelLoader>(this, m_levelNumber)),
	m_isPaused(false)
{
	m_level->loadLevel();
}

void GameLevel::update(sf::Time deltaTime)
{
	checkConditions();
	if (!m_isPaused)
	{
		move(deltaTime);
		checkCollision();
		removePickable();
	}
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
		//m_observer->switchState("GameOver");
	}
	if (CheeseObject::getCheeseCount() == 0)
	{
		this->LoadNextLevel();
	}
	//if time has passed GameOver
}

void GameLevel::LoadNextLevel()
{
	m_levelNumber++;
	m_collidableObjects.clear();
	m_staticObjects.clear();
	m_enemys.clear();
	m_level = std::make_unique<LevelLoader>(this, m_levelNumber);
	m_level->loadLevel();
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
		if (enemys->checkCollision(*obj))
		{
			enemys->handleCollision(*obj);
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


MovablePath GameLevel::getPath(sf::Vector2f pos)
{
	float pos_x = std::floor(pos.x / 64);
	float pos_y = std::floor(pos.y / 64);
    MovablePath path;

    for (auto& floor : m_staticObjects)
    {
        sf::Vector2f floorPos = floor->getPosition();
		float x_index = std::floor(floorPos.x / 64) - pos_x;
		float y_index = std::floor(floorPos.y / 64) - pos_y;

        if ((std::abs(x_index) == 1 && std::abs(y_index) == 0)
			|| std::abs(y_index) == 1 && std::abs(x_index) == 0)
        {
			path.push_back(sf::Vector2f{x_index, y_index});
        }
    }
    return path;
}

void GameLevel::setMapSize(const sf::Vector2f mapSize)
{
	m_mapSize = mapSize;
	setView();
}

void GameLevel::setView()
{
	m_view.setSize(m_mapSize.x, m_mapSize.y);
	m_view.setCenter(m_mapSize.x / 2, m_mapSize.y / 2);
}

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

size_t GameLevel::getEnemyCount() const
{
    return m_enemys.size();
}