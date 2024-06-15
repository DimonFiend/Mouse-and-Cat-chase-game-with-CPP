#include "GameLevel.h"
#include "Observer.h"
#include "WallObject.h"
#include "FloorObject.h"
#include "Resources.h"

GameLevel::GameLevel(Observer* observer) : m_observer(observer)
{
	m_collidableObjects.push_back(std::make_unique<WallObject>(Resources::Instance().getWallTexture(), sf::Vector2f(0, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(Resources::Instance().getWallTexture(), sf::Vector2f(64, 0)));
	m_collidableObjects.push_back(std::make_unique<WallObject>(Resources::Instance().getWallTexture(), sf::Vector2f(0, 64)));

	m_staticObjects.push_back(std::make_unique<FloorObject>(Resources::Instance().getFloorTexture(),sf::Vector2f(64, 64)));

}

void GameLevel::update()
{

}

void GameLevel::render(sf::RenderWindow& window)
{
	for (auto& collidableObject : m_collidableObjects)
	{
		collidableObject->draw(window);
	}

	for (auto& staticObject : m_staticObjects)
	{
		staticObject->draw(window);
	}
}

void GameLevel::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{

}
