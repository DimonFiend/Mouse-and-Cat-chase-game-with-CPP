#include "GameLevel.h"
#include "Observer.h"
#include "Resources.h"
#include "MousePlayer.h"
#include "ObjectsInclude.h"
#include "PresentObject.h"
#include "FloorObject.h"

GameLevel::GameLevel(Observer* observer) : m_observer(observer)
{
	
	
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
