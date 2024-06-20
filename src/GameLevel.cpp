#include "GameLevel.h"
#include "Observer.h"
#include "WallObject.h"
#include "FloorObject.h"
#include "Resources.h"
#include "MousePlayer.h"
#include "CheeseObject.h"

GameLevel::GameLevel(Observer* observer) : m_observer(observer)
{
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(0, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(64, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(0, 64)));
	m_collidableObjects.push_back(std::make_unique<CheeseObject>(sf::Vector2f(200, 200)));
	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(200, 200)));
	m_collidableObjects.push_back(std::make_unique<CheeseObject>(sf::Vector2f(300, 200)));
	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(300, 200)));
	m_collidableObjects.push_back(std::make_unique<CheeseObject>(sf::Vector2f(200, 300)));
	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(200, 300)));
	m_collidableObjects.push_back(std::make_unique<CheeseObject>(sf::Vector2f(400, 300)));
	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(400, 300)));
	m_collidableObjects.push_back(std::make_unique<CheeseObject>(sf::Vector2f(300, 400)));
	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(300, 400)));

	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(64, 64)));
	m_player = std::make_unique<MousePlayer>(sf::Vector2f(128, 128));

}

void GameLevel::update(sf::Time deltaTime)
{
	for (auto& collidableObject : m_collidableObjects)
	{
		if (collidableObject->checkCollision(*m_player))
		{
			collidableObject->handleCollision(*m_player);
		}
	}

	m_player->move(deltaTime);
	removePickable();
}
void GameLevel::removePickable()
{
	//erase if
	m_collidableObjects.erase(std::remove_if(m_collidableObjects.begin(), m_collidableObjects.end(), [](const std::unique_ptr<CollidableObject>& collidableObject)
		{ return collidableObject->getToDelete(); }), m_collidableObjects.end());
}
void GameLevel::render(sf::RenderWindow& window)
{
	for (auto& staticObject : m_staticObjects)
	{
		staticObject->draw(window);
	}

	for (auto& collidableObject : m_collidableObjects)
	{
		collidableObject->draw(window);
	}

	m_player->draw(window);

}

void GameLevel::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{

}
