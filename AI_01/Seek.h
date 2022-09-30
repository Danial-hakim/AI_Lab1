#pragma once
#include "NPC.h"

class Seek : public NPC
{
public:

	virtual SteeringOutput getSteering() override;

private:
	float maxAcceleration = 0.5f;

};