#include "GameState.h"
#include "objectCollision.h"
#include "Transform.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 0,0};
	player.transform.m_facing = 0;
	

	asteriod[0].transform.m_position = vec2{110,-200 };
	asteriod[0].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[0].rigidbody.addTorque(0);

	asteriod[1].transform.m_position = vec2{ 210,-200 };
	asteriod[1].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[1].rigidbody.addTorque(0);

	asteriod[2].transform.m_position = vec2{ 310,-200 };
	asteriod[2].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[2].rigidbody.addTorque(0);

	asteriod[3].transform.m_position = vec2{ 410,-200 };
	asteriod[3].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[3].rigidbody.addTorque(0);

	asteriod[4].transform.m_position = vec2{ 510,-200 };
	asteriod[4].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[4].rigidbody.addTorque(0);

	asteriod[5].transform.m_position = vec2{ 610,-200 };
	asteriod[5].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[5].rigidbody.addTorque(0);

	asteriod[6].transform.m_position = vec2{ 710,-200 };
	asteriod[6].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[6].rigidbody.addTorque(0);

	asteriod[7].transform.m_position = vec2{ 810,-200 };
	asteriod[7].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[7].rigidbody.addTorque(0);

	asteriod[8].transform.m_position = vec2{ 910,-200 };
	asteriod[8].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[8].rigidbody.addTorque(0);

	asteriod[9].transform.m_position = vec2{ 1010,-200 };
	asteriod[9].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[9].rigidbody.addTorque(0);

	asteriod[10].transform.m_position = vec2{ -110,-200 };
	asteriod[10].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[10].rigidbody.addTorque(0);

	asteriod[11].transform.m_position = vec2{ -210,-200 };
	asteriod[11].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[11].rigidbody.addTorque(0);

	asteriod[12].transform.m_position = vec2{ -310,-200 };
	asteriod[12].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[12].rigidbody.addTorque(0);

	asteriod[13].transform.m_position = vec2{ -410,-200 };
	asteriod[13].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[13].rigidbody.addTorque(0);

	asteriod[14].transform.m_position = vec2{ -1010,-200 };
	asteriod[14].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[14].rigidbody.addTorque(0);

	asteriod[15].transform.m_position = vec2{ -610,-200 };
	asteriod[15].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[15].rigidbody.addTorque(0);

	asteriod[16].transform.m_position = vec2{ -710,-200 };
	asteriod[16].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[16].rigidbody.addTorque(0);

	asteriod[17].transform.m_position = vec2{ -810,-200 };
	asteriod[17].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[17].rigidbody.addTorque(0);

	asteriod[18].transform.m_position = vec2{ -910,-200 };
	asteriod[18].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[18].rigidbody.addTorque(0);

	asteriod[19].transform.m_position = vec2{ -1010,-200 };
	asteriod[19].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[19].rigidbody.addTorque(0);

	asteriod[20].transform.m_position = vec2{ 110,-400 };
	asteriod[20].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[20].rigidbody.addTorque(0);

	asteriod[21].transform.m_position = vec2{ 210,-400 };
	asteriod[21].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[21].rigidbody.addTorque(0);

	asteriod[22].transform.m_position = vec2{ 310,-400 };
	asteriod[22].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[22].rigidbody.addTorque(0);

	asteriod[23].transform.m_position = vec2{ 410,-400 };
	asteriod[23].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[23].rigidbody.addTorque(0);

	asteriod[24].transform.m_position = vec2{ 1010,-400 };
	asteriod[24].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[24].rigidbody.addTorque(0);

	asteriod[25].transform.m_position = vec2{ 610,-400 };
	asteriod[25].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[25].rigidbody.addTorque(0);
	
	asteriod[26].transform.m_position = vec2{ 710,-400 };
	asteriod[26].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[26].rigidbody.addTorque(0);

	asteriod[27].transform.m_position = vec2{ 810,-400 };
	asteriod[27].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[27].rigidbody.addTorque(0);

	asteriod[28].transform.m_position = vec2{ 910,-400 };
	asteriod[28].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[28].rigidbody.addTorque(0);

	asteriod[29].transform.m_position = vec2{ 1010,-400 };
	asteriod[29].rigidbody.addImpulse(vec2{ 0,0 });
	asteriod[29].rigidbody.addTorque(0);

	target[0].trans.m_position = vec2{ 1000, 1600 };
	target[0].rigid.addTorque(25);
	
	target[1].trans.m_position = vec2{ -1000, 1600 };
	target[1].rigid.addTorque(25);
	
	target[2].trans.m_position = vec2{ 600, 1200 };
	target[2].rigid.addTorque(25);
	
	target[3].trans.m_position = vec2{ -600, 1200 };
	target[3].rigid.addTorque(25);
	
	target[4].trans.m_position = vec2{ 0, 800 };
	target[4].rigid.addTorque(25);
	
	bullet.timer = 0;
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this,bullet);
	tractor.update(deltaTime, *this);
	

	for (int i = 0; i < 30; ++i)
		asteriod[i].update(deltaTime, *this);

	for (int i = 0; i < 30; ++i)
		PlayerAstroidCollision(player, asteriod[i]);
	
	for (int i = 0; i < 30 - 1; ++i)
		for (int j = i + 1; j < 30; ++j)
		{
			AstroidCollision(asteriod[i], asteriod[j]);
		}

	for (int i = 0; i < 30; ++i)
		BulletAsteroidCollision(bullet, asteriod[i]);

	for (int i = 0; i < 30; ++i)
		TractorBulletCollision(tractor, bullet);

	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 5; j++)
			targetAstroidCollision(target[j], asteriod[i]);

	for (int i = 0; i < 5; ++i)
		BulletTargetCollision(bullet, target[i]);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	bullet.draw(cam);
	tractor.draw(cam);
	
	for (int i = 0; i < 30; ++i)
		asteriod[i].draw(cam);

	for (int i = 0; i < 5; ++i)
		target[i].draw(cam);
}
