#pragma once
#include "MovingObject.h"

class CheeseObject;
class MousePlayer : public MovingObject {

private:
	sf::Vector2f getDirection() const;
	unsigned int m_lives;
	unsigned int m_score;
	bool m_moving;
public:
	MousePlayer(sf::Vector2f pos);

	void setMoving() { m_moving = !m_moving;};
	bool getMoving() const { return m_moving;};

	virtual void handleCollision(MovingObject& other) override;
	virtual void handleCollision(CheeseObject& other) override;
	virtual bool checkCollision(MovingObject& other) override;
	virtual void move(sf::Time deltaTime) override;
};