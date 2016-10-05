#pragma once
#include "RigidBody.h"

class spaceShipLocomotion
{
	

	float vertThrust;
	float horzThurst;
	float stopAction;
	
	float breakPower;
	float turnSpeed;
	float speed;
	float maxSpeed;

public:

	spaceShipLocomotion();
	void doThrust(float value);
	void doTurn(float value);

	void doStop(float value);

	void update(const Transform &trans, RigidBody &rigidbody);
};
