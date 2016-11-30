#pragma once

#include "vec2.h"
#include "Transform.h"

class RigidBody
{
public:
	RigidBody();

	vec2 force, impulse;
	vec2 velocity; //represents the change in position
	float angularVelocity;
	float angularAcceleration;
	vec2 acceleration;
	float mass, drag, angularDrag;
	float torque;

	void addForce(const vec2 &a_force);
	void addImpulse(const vec2 &a_impulse);
	void addTorque(float a_torque);

	void integrate(Transform &trans, float deltatime, bool bounds = true);

	void debugDraw(const mat3& T, const Transform &trans);

};
