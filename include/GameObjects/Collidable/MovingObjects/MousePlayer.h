#pragma once
#include "MovingObject.h"

class Animator;
class GameLevel;
class EnemyObject;
class MousePlayer : public MovingObject {

private:
	GameLevel* m_manager;
	sf::Vector2f getDirection();
	unsigned int m_keys;
	static unsigned int m_lives;
	static unsigned int m_score;

	void checkMapBounds();
	void handleEnemy();
public:
	MousePlayer(sf::Vector2f pos, GameLevel* manager);

	static const unsigned int getLives() {return m_lives;};
	static const unsigned int getScore() {return m_score;};
	void setScore(int score);

	void respawn();
	virtual void handleCollision(CatEnemy& other) override;
	virtual void handleCollision(SmartCatEnemy& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	virtual void handleCollision(CheeseObject& other) override;
	virtual void handleCollision(CollidableObject& other) override;
	virtual void handleCollision(KeyObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;
	virtual void handleCollision(TimePresent& other) override;
	virtual void handleCollision(FreezePresent& other) override;
	virtual void handleCollision(DestroyPresent& other) override;
	virtual void handleCollision(LifePresent& other) override;
	virtual void move(sf::Time deltaTime) override;
};