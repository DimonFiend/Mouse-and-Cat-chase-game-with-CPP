#include "WallObject.h"
#include "Resources.h"
#include "MovingObject.h"
#include "CatEnemy.h"
#include "SmartCatEnemy.h"

WallObject::WallObject(sf::Vector2f pos)
	: CollidableObject(pos, Resources::instance().getTextureRect(Objects::Wall))
{}

//=============================================================================
// handleCollision
// This function is a double dispatch function that handles the collision between	
// the WallObject and moving objects.
void WallObject::handleCollision(CollidableObject& other)
{
	other.handleCollision(*this);
}

void WallObject::handleCollision(MousePlayer& other)
{
	other.handleCollision(*this);
}

void WallObject::handleCollision(CatEnemy& other)
{
	other.handleCollision(*this);
}

void WallObject::handleCollision(SmartCatEnemy& other)
{
	other.handleCollision(*this);
}