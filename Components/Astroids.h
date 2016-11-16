#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Astroid
{
public:
	Transform transform;
	Collider collider;
	RigidBody rigidbody;

	Astroid();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};