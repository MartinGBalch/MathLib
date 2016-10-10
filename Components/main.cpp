#include "sfwdraw.h"
#include "vec2.h"
#include <cstdio>
#include "Transform.h"
#include "flops.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
#include "SpaceshipController.h"
using namespace sfw;

void main()
{
	float W = 800, H = 640;
	sfw::initContext(W,H);
	float steps = 100;
	bool tick = false;

	vec2 start = { 200,300 },
		end = { 900,800 },
		mid = { 0, 1100 };

	Transform playerTransform(400, 400);
	playerTransform.scale = { 5,5 };

	spaceShipLocomotion playerLoco;
	SpaceshipController playerCTRL;

	RigidBody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };

	playerTransform.scale = { 24,24 };
	sfw::setBackgroundColor(BLACK);
			
	while (sfw::stepContext())
	{
		float deltaTime = getDeltaTime();

		/*if (getKey('W'))
		{
			playerRigidbody.acceleration.y += 10.0f;
		}
		else if (getKey('S'))
		{
			playerRigidbody.acceleration.y -= 10.0f;
		}

		if (getKey('D'))
		{
			playerRigidbody.acceleration.x += 10.0f;
		}
		else if (getKey('A'))
		{
			playerRigidbody.acceleration.x -= 10.0f;
		}

		if (getKey('Q'))
		{
			playerRigidbody.angularAcceleration += 1.0f;
		}
		if (getKey('E'))
		{
			playerRigidbody.angularAcceleration -= 1.0f;
		}
*/
		if (playerTransform.position.x > W)
		{
			playerTransform.position.x = 0.0f;
		}
		else if (playerTransform.position.x < 0.0f)
		{
			playerTransform.position.x = W;
		}

		if (playerTransform.position.y > H)
		{
			playerTransform.position.y = 0.0f;
		}
		else if (playerTransform.position.y < 0.0f)
		{
			playerTransform.position.y = H;
		}

		playerCTRL.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);
	}

	sfw::termContext();
}