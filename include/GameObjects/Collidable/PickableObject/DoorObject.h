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
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
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