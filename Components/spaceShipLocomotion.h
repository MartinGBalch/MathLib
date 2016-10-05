#pragma once
#include "RigidBody.h"

class spaceShipLocomotion
{
	

	float vertThrust;
	float horzThurst;
	
	float speed;
	float maxSpeed;

public:

	spaceShipLocomotion();
	void doThrust(float value);
	void doTurn(float value);

	void update(RigidBody &rigidbody, float deltaTime);
};
