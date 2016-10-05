#include "RigidBody.h"

RigidBody::RigidBody()
{
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
}

void RigidBody::addForce(const vec2 & force)
{
	acceleration += force;
}

void RigidBody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}

void RigidBody::addTorque(float torque)
{
	angularAcceleration += torque;
}

void RigidBody::integrate(Transform & trans, float deltatime)
{
	// perform euler integration! :0

	velocity += acceleration * deltatime;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;

	trans.position = trans.position + velocity * deltatime;
	trans.facing = trans.facing + angularVelocity * deltatime;
}
