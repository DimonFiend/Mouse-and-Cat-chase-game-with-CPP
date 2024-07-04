#pragma once

#include "MovingObject.h"

class EnemyObject : public MovingObject {

private:
	bool m_frozen;
	sf::Clock m_frozenClock;
	sf::Clock m_speak;

public:
	EnemyObject(float speed, sf::Vector2f pos, sf::IntRect obj);

	virtual void move(sf::Time deltaTime) override { (void)deltaTime; };
	virtual void move(sf::Time deltaTime, GameLevel* manager) = 0;
	sf::Vector2f calcRelativePos(sf::Vector2f pos) const;
	bool isFrozen() const { return m_frozen; };
	void setFreeze();
	bool checkFreezeStatus();
	virtual void respawn();
	void soundOnPlayerHit() const;
	void catSpeak();
};