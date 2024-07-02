#pragma once
#include "PickableObject.h"
#include "ObjectsInclude.h"
#include "MousePlayer.h"

class CheeseObject : public PickableObject {
private:
	static unsigned int m_cheeseCount;
public:
	CheeseObject(sf::Vector2f pos);
	static unsigned int getCheeseCount() { return m_cheeseCount; };
	virtual ~CheeseObject() { m_cheeseCount--; };
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CatEnemy& other) override { (void)other; };
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(CheeseObject& other) { (void)other; };
	virtual void handleCollision(KeyObject& other) { (void)other; };
	virtual void handleCollision(DoorObject& other) { (void)other; };
	virtual void handleCollision(WallObject& other) { (void)other; };
	virtual void handleCollision(TimePresent& other) override { (void)other; };
	virtual void handleCollision(FreezePresent& other) override { (void)other; };
	virtual void handleCollision(DestroyPresent& other) override { (void)other; };
	virtual void handleCollision(LifePresent& other) override { (void)other; };
};