///=======================================================================
/// \file	DoorObject.h
/// \brief	A class that represents a door object in the game.
/// 		This class is a derived class from PickableObject.
/// 	    and is responsible for the door object in the game.
///         has a static member that counts the number of doors in the game.

#pragma once
#include "PickableObject.h"
#include "SmartCatEnemy.h"
#include "CatEnemy.h"

class GameLevel;
class DoorObject : public PickableObject {
private:
	static unsigned int m_doorCount;
public:
	DoorObject(sf::Vector2f pos);
	virtual ~DoorObject() { m_doorCount--; };

	//Double dispatch
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	//not relevant
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(WallObject& other) override { (void)other; };
	virtual void handleCollision(TimePresent& other) override { (void)other; };
	virtual void handleCollision(FreezePresent& other) override { (void)other; };
	virtual void handleCollision(DestroyPresent& other) override { (void)other; };
	virtual void handleCollision(LifePresent& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(CatEnemy& other) override;

	static unsigned int getDoorCount() { return m_doorCount; };
	void handlePlayer(GameLevel* manager);
};