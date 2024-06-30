#pragma once

#include "EnemyObject.h"
typedef std::vector<sf::Vector2i> MovablePath;
class CatEnemy : public EnemyObject {

private:
	sf::Vector2f getDirection(const MovablePath& path);
	sf::Clock m_timer;

	void handleObstruct();
	sf::Vector2f switchDirection(const MovablePath& path);
	void checkMapBounds(GameLevel* manager);
public:
	CatEnemy(sf::Vector2f pos);
	virtual void move(sf::Time deltaTime, GameLevel* manager) override;
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	virtual void handleCollision(CatEnemy& other) override;
	virtual void handleCollision(SmartCatEnemy& other) override { (void)other; };
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(CheeseObject& other) override { (void)other; };
	virtual void handleCollision(KeyObject& other) override { (void)other; };
};