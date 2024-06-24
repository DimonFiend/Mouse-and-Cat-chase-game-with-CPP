#pragma once
#include "Presents.h"

class MovingObject;
class FreezePresent : public Presents {
public:
	FreezePresent() = default;
	virtual ~FreezePresent() = default;
	virtual void handleCollision(MovingObject& other) override;
	virtual Objects PresentId() override;
};