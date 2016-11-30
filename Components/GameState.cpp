#include "GameState.h"
#include "objectCollision.h"
#include "Transform.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 0,0};
	player.transform.m_facing = 0;
	

	asteriod[0].transform.m_position = vec2{100,200 };
	asteriod[0].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[0].rigidbody.addTorque(4);

	asteriod[1].transform.m_position = vec2{ 200,200 };
	asteriod[1].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[1].rigidbody.addTorque(4);

	asteriod[2].transform.m_position = vec2{ 300,200 };
	asteriod[2].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[2].rigidbody.addTorque(4);

	asteriod[3].transform.m_position = vec2{ 400,200 };
	asteriod[3].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[3].rigidbody.addTorque(4);

	asteriod[4].transform.m_position = vec2{ 500,200 };
	asteriod[4].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[4].rigidbody.addTorque(4);

	asteriod[5].transform.m_position = vec2{ 600,200 };
	asteriod[5].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[5].rigidbody.addTorque(4);

	asteriod[6].transform.m_position = vec2{ 700,200 };
	asteriod[6].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[6].rigidbody.addTorque(4);

	asteriod[7].transform.m_position = vec2{ 800,200 };
	asteriod[7].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[7].rigidbody.addTorque(4);

	asteriod[8].transform.m_position = vec2{ 900,200 };
	asteriod[8].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[8].rigidbody.addTorque(4);

	asteriod[9].transform.m_position = vec2{ 1000,200 };
	asteriod[9].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[9].rigidbody.addTorque(4);

	target[0].trans.m_position = vec2{ 1000, 1600 };
	target[0].rigid.addTorque(25);
	
	target[1].trans.m_position = vec2{ -1000, 1600 };
	target[1].rigid.addTorque(25);
	
	target[2].trans.m_position = vec2{ 600, 1200 };
	target[2].rigid.addTorque(25);
	
	target[3].trans.m_position = vec2{ -600, 1200 };
	target[3].rigid.addTorque(25);
	
	target[4].trans.m_position = vec2{ 0, 1000 };
	target[4].rigid.addTorque(25);
	
	bullet.timer = 0;
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this,bullet);
	tractor.update(deltaTime, *this);
	

	for (int i = 0; i < 10; ++i)
		asteriod[i].update(deltaTime, *this);

	for (int i = 0; i < 10; ++i)
		PlayerAstroidCollision(player, asteriod[i]);

	for (int i = 0; i < 10 - 1; ++i)
		for (int j = i + 1; j < 10; ++j)
			AstroidCollision(asteriod[i], asteriod[j]);

	for (int i = 0; i < 10; ++i)
		BulletAsteroidCollision(bullet, asteriod[i]);

	for (int i = 0; i < 10; ++i)
		TractorBulletCollision(tractor, bullet);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 5; j++)
			targetAstroidCollision(target[j], asteriod[i]);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	bullet.draw(cam);
	tractor.draw(cam);
	
	for (int i = 0; i < 10; ++i)
		asteriod[i].draw(cam);

	for (int i = 0; i < 5; ++i)
		target[i].draw(cam);
}
