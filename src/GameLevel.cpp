#include "GameLevel.h"
#include "Observer.h"
#include "WallObject.h"
#include "FloorObject.h"
#include "Resources.h"
#include "MousePlayer.h"

GameLevel::GameLevel(Observer* observer) : m_observer(observer)
{
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(0, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(32, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(sf::Vector2f(0, 32)));

	m_staticObjects.push_back(std::make_unique<FloorObject>(sf::Vector2f(32, 32)));
	m_movingObjects.push_back(std::make_unique<MousePlayer>(sf::Vector2f(128, 128)));

}

void GameLevel::update(sf::Time deltaTime)
{
	for (auto& movingObject : m_movingObjects)
	{
		movingObject->move(deltaTime);
	}
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

	for (auto& movingObject : m_movingObjects)
	{
		movingObject->draw(window);
	}
}

void GameLevel::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{

}
