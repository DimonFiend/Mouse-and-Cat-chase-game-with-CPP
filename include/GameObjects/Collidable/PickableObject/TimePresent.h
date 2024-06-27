#pragma once
#include "Presents.h"

class CollidableObject;
class TimePresent : public Presents {
public:
	TimePresent() = default;
	virtual ~TimePresent() = default;
	virtual void handleCollision(CollidableObject& other) override;
	virtual Objects PresentId() override;
};