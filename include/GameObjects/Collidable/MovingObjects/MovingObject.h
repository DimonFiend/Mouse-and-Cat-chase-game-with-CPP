///=======================================================================
/// \file MovingObject.h
/// \brief This file contains the declaration of the MovingObject class.
/// 
/// The MovingObject class is a derived class from CollidableObject class.
/// It is an abstract class that represents a moving object in the game.
/// It contains the speed, spawn position, last position, direction, and animator.
/// It also contains the methods to move the object, set the speed, spawn position, last position.
/// ========================================================================

#pragma once
#include "CollidableObject.h"
#include "Utilities.h"
#include "Animator.h"
#include <SFML/Audio.hpp>

class GameLevel;
class MovingObject : public CollidableObject {
private:
	float m_speed;
	sf::Vector2f m_spawn;
	sf::Vector2f m_lastPos;
	std::unique_ptr<Animator> m_animator;
protected:
	Direction m_direction;
public:
	MovingObject(float speed, sf::Vector2f pos, sf::IntRect obj);
	MovingObject& operator=(MovingObject& other);
	virtual ~MovingObject() = default;
	virtual void move(sf::Time deltaTime) = 0;

	void setSpeed(float speed) { m_speed = speed; };
	void setSpawn(sf::Vector2f spawn) { m_spawn = spawn; };
	void setLastPos(sf::Vector2f lastPos) { m_lastPos = lastPos;};

	sf::Vector2f getSpawn() const { return m_spawn; };
	sf::Vector2f getLastPos() const { return m_lastPos; };
	float getSpeed() const { return m_speed; };

	sf::Vector2f enumToVector() const;
	Direction vectorToEnum(const sf::Vector2i& pos) const;
	sf::Vector2i toGridIndex(const sf::Vector2f& position) const;
	void setAnimator();
	void Animate(sf::Time deltaTime, Direction direction) const;

};