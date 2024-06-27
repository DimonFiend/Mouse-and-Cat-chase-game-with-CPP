#pragma once
#include "Presents.h"

class MovingObject;
class DestroyPresent : public Presents {
public:
	DestroyPresent() = default;
	virtual ~DestroyPresent() = default;
	virtual void handleCollision(CollidableObject& other) override;
	virtual Objects PresentId() override;
};