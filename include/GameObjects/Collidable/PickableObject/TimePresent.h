#pragma once
#include "Presents.h"

class MovingObject;
class TimePresent : public Presents {
public:
	TimePresent() = default;
	virtual ~TimePresent() = default;
	virtual void handleCollision(MovingObject& other) override;
	virtual Objects PresentId() override;
};