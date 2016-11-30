#include "spaceShipLocomotion.h"
#include "sfwdraw.h"
#include "RigidBody.h"
using namespace sfw;

RigidBody playerRigidbody;

spaceShipLocomotion::spaceShipLocomotion()
{
	vertThrust = 0.0f;
	horzThurst = 0.0f;
	stopAction = 2.0f;
	breakPower = 10.0f;

	turnSpeed = 2.0f;
	speed = 100.0f;
	maxSpeed = 200.0f;
}

void spaceShipLocomotion::doThrust(float value)
{
	vertThrust += value;
}

void spaceShipLocomotion::doTurn(float value)
{
	horzThurst += value;

} 

void spaceShipLocomotion::doStop(float value) {stopAction += value;}

void spaceShipLocomotion::update(const Transform &trans, RigidBody &rigidbody)
{
	vec2 w = trans.getUp();
	rigidbody.addForce(w * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThurst);	
	
	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThurst = vertThrust = stopAction = 0;
		
	if (rigidbody.velocity.x > 110.0f) rigidbody.velocity.x = 110.0f;
	if (rigidbody.velocity.x < -110.0f) rigidbody.velocity.x = -110.0f;
	if (rigidbody.velocity.y > 110.0f) rigidbody.velocity.y = 110.0f;
	if (rigidbody.velocity.y < -110.0f) rigidbody.velocity.y = -110.0f;


	//// zero out the thrust values


	
}
