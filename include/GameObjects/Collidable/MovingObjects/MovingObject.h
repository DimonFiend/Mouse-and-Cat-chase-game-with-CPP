#pragma once
#include "CollidableObject.h"

class MousePlayer;
class EnemyObject;
class WallObject;
class DoorObject;
class FreezePresent;
class TimePresent;
class DestroyPresent;
class KeyObject;
class CheeseObject;
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
	void setSpawn(sf::Vector2f spawn) { m_spawn = spawn; };
	void setLastPos(sf::Vector2f lastPos) { m_lastPos = lastPos;};
	sf::Vector2f getSpawn() const { return m_spawn; };
	sf::Vector2f getLastPos() const { return m_lastPos; };

	virtual void handleCollision(CheeseObject& other) = 0;
	virtual void handleCollision(KeyObject& other) = 0;
	virtual void handleCollision(DoorObject& other) = 0;
	virtual void handleCollision(WallObject& other) = 0;
};