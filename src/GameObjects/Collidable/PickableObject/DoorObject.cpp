#include "DoorObject.h"
#include "Resources.h"
#include "MovingObject.h"
#include "EnemyObject.h"
#include "GameLevel.h"
#include "FloorObject.h"

DoorObject::DoorObject(sf::Vector2f pos)
	: PickableObject(pos, Resources::instance().getTextureRect(Objects::Door))
{}

void DoorObject::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void DoorObject::handleCollision(MousePlayer& other)
{
}

void DoorObject::handleCollision(SmartCatEnemy& other)
{
	other.handleCollision(*this);
}

void DoorObject::handleCollision(CatEnemy& other)
{
	other.handleCollision(*this);
}

void DoorObject::handlePlayer(GameLevel* manager)
{
	setToDelete();
	sf::Vector2f pos = m_sprite.getPosition();
	pos.x -= 32;
	pos.y -= 32;
	manager->setStatic(std::make_unique<FloorObject>(pos));
	Resources::instance().playSound(Sounds::DoorLock);
}