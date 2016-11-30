#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Target
{
public:
	Transform trans;
	Collider collider;
	RigidBody rigid;

	unsigned int color;
	int hp;


	Target();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};
