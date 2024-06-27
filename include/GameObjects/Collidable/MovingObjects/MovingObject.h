#pragma once
#include "CollidableObject.h"

class MovingObject : public CollidableObject {

private:
	float m_speed;
	sf::Vector2f m_spawn;
	sf::Vector2f m_lastPos;
public:
	MovingObject(float speed = 50);
	virtual ~MovingObject() = default;
	float getSpeed() const {return m_speed;};
	virtual void move(sf::Time deltaTime) = 0;
	void setSpeed(float speed) { m_speed = speed; };
	void setSpawn(sf::Vector2f spawn) { m_spawn = spawn; };
	void setLastPos(sf::Vector2f lastPos) { m_lastPos = lastPos;};
	sf::Vector2f getSpawn() const { return m_spawn; };
	sf::Vector2f getLastPos() const { return m_lastPos; };
};