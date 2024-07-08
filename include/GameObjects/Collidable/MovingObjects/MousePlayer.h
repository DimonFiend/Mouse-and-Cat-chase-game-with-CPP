///=======================================================================
/// \file	MousePlayer.h
/// \brief	This file contains the declaration of the MousePlayer class.
///		    The MousePlayer class is a derived class from the MovingObject class.
/// 	    It represents the player in the game. It contains the methods to
/// 	    move the player, handle collision with other objects, and check the map bounds.

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
	unsigned int m_lives;
	unsigned int m_score;

	void checkMapBounds();
	void handleEnemy();
public:
	MousePlayer(sf::Vector2f pos, GameLevel* manager);
	MousePlayer& operator=(const MousePlayer& other);

	//getters
	const unsigned int getLives() const {return m_lives;};
	const unsigned int getScore() const {return m_score;};
	unsigned int getKeys() const {return m_keys; };

	//setters
	void setScore(int score);

	void respawn();
	virtual void move(sf::Time deltaTime) override;

	//double dispatch
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
};