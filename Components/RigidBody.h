#pragma once

#include "vec2.h"
#include "Transform.h"

class RigidBody
{
public:
	RigidBody();

	vec2 velocity; //represents the change in position
	float angularVelocity;
	float angularAcceleration;
	vec2 acceleration;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);

	void addTorque(float torque);

	void integrate(Transform &trans, float deltatime);

};
