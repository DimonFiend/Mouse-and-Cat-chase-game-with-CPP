#pragma once
#include "Resources.h"

class MovingObject;
class Presents {
private:
	bool m_toDelete;
public:
	Presents() :m_toDelete(false) {};
	~Presents() = default;
	virtual void handleCollision(MovingObject& other) = 0;
	virtual Objects PresentId() = 0;
	void setToDelete() { m_toDelete = !m_toDelete; };
	bool toDelete() const { return m_toDelete; };
};