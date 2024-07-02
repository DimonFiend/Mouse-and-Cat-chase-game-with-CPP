#pragma once

#include "EnemyObject.h"
#include <iostream>

typedef std::unique_ptr<sf::Vector2i[]> Predecessors;

class SmartCatEnemy : public EnemyObject {

private:
	void getDirection(GameLevel* manager);
	void directionBfs(GameLevel* manager);
	void nextPath(const Predecessors& pred, GameLevel* manager, int mapWidth);
	Predecessors initializePred(const sf::Vector2i& mapSize) const;
	void pathToEnum(const sf::Vector2i& curr, const sf::Vector2i& next);

public:
	SmartCatEnemy(sf::Vector2f pos);
	virtual ~SmartCatEnemy() = default;
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override { (void)other; };
	virtual void handleCollision(CatEnemy& other) override;
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
	virtual void handleCollision(TimePresent& other) override { (void)other; };
	virtual void handleCollision(FreezePresent& other) override { (void)other; };
	virtual void handleCollision(DestroyPresent& other) override { (void)other; };
	virtual void handleCollision(LifePresent& other) override { (void)other; };
};