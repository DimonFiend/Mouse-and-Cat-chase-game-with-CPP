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
	m_level(std::make_unique<LevelLoader>(this, m_levelNumber))
{
	m_level->loadLevel();
}

void GameLevel::update(sf::Time deltaTime)
{
	
	move(deltaTime);
	checkCollision();
	removePickable();
	//game over
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

void GameLevel::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	if (event.Closed)
	{
		window.close();
	}
}

void GameLevel::move(sf::Time deltaTime)
{
	m_player->move(deltaTime);
	for (auto& enemy : m_enemys)
	{
		enemy->move(deltaTime);
	}
}

void GameLevel::checkCollision()
{
	for (auto& collidableObject : m_collidableObjects)
	{
		if (collidableObject->checkCollision(*m_player))
		{
			collidableObject->handleCollision(*m_player);
		}

		for (auto& enemy : m_enemys)
		{
			if (collidableObject->checkCollision(*enemy))
			{
				collidableObject->handleCollision(*enemy);
			}
		}
	}

	for (auto& enemy : m_enemys)
	{
		if (enemy->checkCollision(*m_player))
		{
			enemy->handleCollision(*m_player);
		}
	}
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