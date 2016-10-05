#include "spaceShipLocomotion.h"
#include "sfwdraw.h"
#include "RigidBody.h"
using namespace sfw;

RigidBody playerRigidbody;

spaceShipLocomotion::spaceShipLocomotion()
{
	vertThrust = 0.0f;
	horzThurst = 0.0f;

	speed = 10.0f;
	maxSpeed = 100.0f;
}

void spaceShipLocomotion::doThrust(float value)
{
	if (getKey('W'))
	{
		vertThrust += 20.f;
	}
	if (getKey('S'))
	{
		vertThrust -= 20.f;
	}
}

void spaceShipLocomotion::doTurn(float value)
{
	if (getKey('D'))
	{
		horzThurst += 20.f;
	}
	if (getKey('A'))
	{
		horzThurst -= 20.f;
	}

}

void spaceShipLocomotion::update(RigidBody &rigidbody, float deltaTime)
{
	

	rigidbody.acceleration.x = horzThurst * speed;
	rigidbody.acceleration.y = vertThrust * speed;
	
	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxSpeed;
	}

	vertThrust = 0.0f;
	horzThurst = 0.0f;
}
