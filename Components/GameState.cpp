#include "GameState.h"
#include "objectCollision.h"
#include "Transform.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 960,540};
	player.transform.m_facing = 0;

	asteriod[0].transform.m_position = vec2{ 0,0 };
	asteriod[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteriod[0].rigidbody.addTorque(24);

	asteriod[1].transform.m_position = vec2{ 400,400 };
	asteriod[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteriod[1].rigidbody.addTorque(-24);

	bullet.timer = 0;
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this,bullet);
	tractor.update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		asteriod[i].update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		PlayerAstroidCollision(player, asteriod[i]);


	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AstroidCollision(asteriod[i], asteriod[j]);



	for (int i = 0; i < 2; ++i)
		BulletAsteroidCollision(bullet, asteriod[i], tractor);

	for (int i = 0; i < 2; ++i)
		TractorAsteroidCollision(tractor, asteriod[i]);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	bullet.draw(cam);
	tractor.draw(cam);
	for (int i = 0; i < 2; ++i)
		asteriod[i].draw(cam);
}
