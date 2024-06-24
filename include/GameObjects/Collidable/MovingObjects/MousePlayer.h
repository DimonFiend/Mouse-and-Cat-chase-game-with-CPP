#pragma once
#include "MovingObject.h"

class MousePlayer : public MovingObject {

private:
	sf::Vector2f getDirection() const;
	unsigned int m_keys;
	static unsigned int m_lives;
	static unsigned int m_score;

public:
	MousePlayer(sf::Vector2f pos);

	static const unsigned int getLives() {return m_lives;};
	static const unsigned int getScore() {return m_score;};

	virtual void handleCollision(EnemyObject& other) override;
	virtual void handleCollision(WallObject& other) override;
	virtual void handleCollision(DoorObject& other) override;
	virtual void handleCollision(TimePresent& other) override;
	virtual void handleCollision(FreezePresent& other) override;
	virtual void handleCollision(DestroyPresent& other) override;
	virtual void handleCollision(CheeseObject& other) override;
	virtual void handleCollision(KeyObject& other) override;
	virtual void handleCollision(MousePlayer& other) override;

	virtual bool checkCollision(CollidableObject& other) override;

	virtual void move(sf::Time deltaTime) override;
};