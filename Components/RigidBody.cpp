#include "RigidBody.h"
#include "sfwdraw.h"
#include "vec2.h"
using namespace sfw;

RigidBody::RigidBody()
{
	mass = 1;
	drag = .25f;
	angularDrag = 1;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	torque = 0;
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
}

void RigidBody::addForce(const vec2 &a_force) {force += a_force;}

void RigidBody::addImpulse(const vec2 &a_impulse) {impulse += a_impulse;}

void RigidBody::addTorque(float a_torque)
{
	torque += a_torque;
}

void RigidBody::integrate(Transform & trans, float deltatime, bool bounds)
{
	// perform euler integration! :0

	acceleration = force / mass;
	velocity = velocity + acceleration * deltatime + impulse / mass;
	trans.m_position = trans.m_position + velocity * deltatime;
	force = impulse = { 0,0 };

	//Dampening Force
	force = -velocity * drag;
	
	angularAcceleration = torque / mass;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;
	trans.m_facing = trans.m_facing + angularVelocity * deltatime;
	torque = 0;
	torque = -angularVelocity * angularDrag;

	
}

void RigidBody::debugDraw(const mat3& T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	vec2 v = p + velocity;
	vec2 a = acceleration + p;

	drawLine(p.x, p.y, v.x, v.y, CYAN);
	drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}

