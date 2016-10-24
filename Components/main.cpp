#include "sfwdraw.h"
#include "vec2.h"
#include <cstdio>
#include "Transform.h"
#include "flops.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "SpaceshipRenderer.h"
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
	Transform ST1(1, 0);
	Transform ST2(1, 0);
	Transform ST3(1, 0);
	Transform ST4(1, 0);
	

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;
	ST4.m_parent = &ST3;
	

	playerTransform.m_scale = { 5,5 };

	spaceShipLocomotion playerLoco;
	SpaceshipController playerCTRL;
	ShipRenderer playerRender;
	

	RigidBody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };

	//parent
	Transform sunTransform;
	sunTransform.m_position = vec2{ W / 2, H / 2 };
	RigidBody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = .5f;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//Planet1
	Transform arturoPlanetTransform;
	arturoPlanetTransform.m_position = vec2{ 60, 0 };
	arturoPlanetTransform.m_parent = &sunTransform;
	RigidBody arturoPlanetTranformRB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	Transform arturoPlanetTransform2;
	arturoPlanetTransform2.m_position = vec2{ 60, 0 };
	arturoPlanetTransform2.m_parent = &sunTransform;
	RigidBody arturoPlanetTranform2RB;
	PlanetaryMotor plan2motor;
	plan2motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan2renderer(GREEN, 30);
	
	Transform arturoPlanetTransform3;
	arturoPlanetTransform3.m_position = vec2{ 60, 0 };
	arturoPlanetTransform3.m_parent = &sunTransform;
	RigidBody arturoPlanetTranform3RB;
	PlanetaryMotor plan3motor;
	plan3motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan3renderer(GREEN, 20);

	Transform arturoPlanetTransform4;
	arturoPlanetTransform4.m_position = vec2{ 60, 0 };
	arturoPlanetTransform4.m_parent = &arturoPlanetTransform3;
	RigidBody arturoPlanetTranform4RB;
	PlanetaryMotor plan4motor;
	plan4motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan4renderer(GREEN, 20);

	Transform arturoPlanetTransform5;
	arturoPlanetTransform5.m_position = vec2{ 60, 0 };
	arturoPlanetTransform5.m_parent = &arturoPlanetTransform4;
	RigidBody arturoPlanetTranform5RB;
	PlanetaryMotor plan5motor;
	plan5motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan5renderer(GREEN, 20);

	Transform arturoPlanetTransform6;
	arturoPlanetTransform6.m_position = vec2{ 60, 0 };
	arturoPlanetTransform6.m_parent = &arturoPlanetTransform5;
	RigidBody arturoPlanetTranform6RB;
	PlanetaryMotor plan6motor;
	plan6motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan6renderer(GREEN, 20);

	Transform arturoPlanetTransform7;
	arturoPlanetTransform7.m_position = vec2{ 60, 0 };
	arturoPlanetTransform7.m_parent = &arturoPlanetTransform6;
	RigidBody arturoPlanetTranform7RB;
	PlanetaryMotor plan7motor;
	plan7motor.m_rotationSpeed = .5f;
	PlanetaryRenderer plan7renderer(GREEN, 20);
	
	Transform cameraTransform;
	
	playerTransform.m_scale = { 24,24 };
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
		/*if (playerTransform.m_position.x > W)
		{
			playerTransform.m_position.x = 0.0f;
		}
		else if (playerTransform.m_position.x < 0.0f)
		{
			playerTransform.m_position.x = W;
		}

		if (playerTransform.m_position.y > H)
		{
			playerTransform.m_position.y = 0.0f;
		}
		else if (playerTransform.m_position.y < 0.0f)
		{
			playerTransform.m_position.y = H;
		}*/

		/*if (getKey('Q'))
		{
			ST1.m_facing += 0.1;
		}
		if (getKey('W'))
		{
			ST1.m_facing -= 0.1;
		}
		if (getKey('E'))
		{
			ST2.m_facing += 0.1;
		}
		if (getKey('R'))
		{
			ST2.m_facing -= 0.1;
		}
		if (getKey('T'))
		{
			ST3.m_facing += 0.1;
		}
		if (getKey('Y'))
		{
			ST3.m_facing -= 0.1;
		}
		if (getKey('U'))
		{
			ST1.m_facing -= 0.12;
			ST2.m_facing -= 0.12;
			ST3.m_facing -= 0.12;
		}
		if (getKey('D'))
		{
			ST1.m_facing += 0.12;
			ST2.m_facing += 0.12;
			ST3.m_facing += 0.12;
		}
		ST1.m_facing /= 1.2;
		ST2.m_facing /= 1.2;
		ST3.m_facing /= 1.2;*/
		

		playerCTRL.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		

		/*ST1.debugDraw();
		ST2.debugDraw();
		ST3.debugDraw();
		ST4.debugDraw();*/

		sunMotor.update(sunRbody);
		plan1motor.update(arturoPlanetTranformRB);
		plan2motor.update(arturoPlanetTranform2RB);
		plan3motor.update(arturoPlanetTranform3RB);
		plan4motor.update(arturoPlanetTranform4RB);
		plan5motor.update(arturoPlanetTranform5RB);
		plan6motor.update(arturoPlanetTranform6RB);
		plan7motor.update(arturoPlanetTranform7RB);

		sunRbody.integrate(sunTransform, deltaTime);
		arturoPlanetTranformRB .integrate(arturoPlanetTransform , deltaTime);
		arturoPlanetTranform2RB.integrate(arturoPlanetTransform2, deltaTime);
		arturoPlanetTranform3RB.integrate(arturoPlanetTransform3, deltaTime);
		arturoPlanetTranform4RB.integrate(arturoPlanetTransform4, deltaTime);
		arturoPlanetTranform5RB.integrate(arturoPlanetTransform5, deltaTime);
		arturoPlanetTranform6RB.integrate(arturoPlanetTransform6, deltaTime);
		arturoPlanetTranform7RB.integrate(arturoPlanetTransform7, deltaTime);

		cameraTransform.m_position = lerp(cameraTransform.m_position, 
			playerTransform.getGlobalPosition(), getDeltaTime() * 10);

		mat3 proj = translate(400, 320) * scale(.8, .8);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		

		mat3 camera = proj * view;


		playerTransform.debugDraw(camera);
		playerRigidbody.debugDraw(camera,playerTransform);

		sunTransform.debugDraw(camera);
		arturoPlanetTransform.debugDraw(camera);
		arturoPlanetTransform2.debugDraw(camera);
		arturoPlanetTransform3.debugDraw(camera);
		arturoPlanetTransform4.debugDraw(camera);
		arturoPlanetTransform5.debugDraw(camera);
		arturoPlanetTransform6.debugDraw(camera);
		arturoPlanetTransform7.debugDraw(camera);
		cameraTransform.debugDraw(camera);

		playerRender.draw(playerTransform, camera);
	
		
	}

	sfw::termContext();
}