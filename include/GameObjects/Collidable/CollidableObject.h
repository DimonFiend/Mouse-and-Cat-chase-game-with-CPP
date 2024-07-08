/// \file CollidableObject.h
/// \brief A class that represents a collidable object in the game.
/// 
/// This class is a base class for all the collidable objects in the game.
/// It is a derived class from GameObject.

#pragma once
#include "GameObject.h"

class SmartCatEnemy;
class CatEnemy;
class DoorObject;
class WallObject;
class KeyObject;
class CheeseObject;
class MousePlayer;
class TimePresent;
class FreezePresent;
class DestroyPresent;
class LifePresent;
class CollidableObject : public GameObject{
private:
	bool m_toDelete;

public:
	CollidableObject(sf::Vector2f pos, sf::IntRect obj);
	virtual ~CollidableObject() = default;
	CollidableObject& operator=(const CollidableObject& other) = default;

	bool getToDelete() const { return m_toDelete; };
	void setToDelete() { m_toDelete = !m_toDelete; };

	//Double dispatch
	virtual bool checkCollision(CollidableObject& other);
	virtual void handleCollision(CollidableObject& other) = 0;
	virtual void handleCollision(MousePlayer& other) = 0;
	virtual void handleCollision(CatEnemy& other) = 0;
	virtual void handleCollision(CheeseObject& other) = 0;
	virtual void handleCollision(KeyObject& other) = 0;
	virtual void handleCollision(DoorObject& other) = 0;
	virtual void handleCollision(WallObject& other) = 0;
	virtual void handleCollision(SmartCatEnemy& other) = 0;
	virtual void handleCollision(TimePresent& other) = 0;
	virtual void handleCollision(FreezePresent& other) = 0;
	virtual void handleCollision(DestroyPresent& other) = 0;
	virtual void handleCollision(LifePresent& other) = 0;
};