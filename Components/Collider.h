#pragma once
#include"shapes.h"
#include "Transform.h"
#include "collision.h"
#include "RigidBody.h"

class Collider
{
public:
	AABB box;
	Hull hull;

	bool isBox;

	Collider();
	Collider(const vec2 *verts, int size);
	void DebugDraw(const mat3 &T, const Transform &trans);
};

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
								const Transform &BT, const Collider &BC);

CollisionData StaticResolution(Transform & at, RigidBody & ar, const Collider & ac,
							   Transform & bt, const Collider & bc, float bounciness = 1);

CollisionData DynamicResolution(Transform &at, RigidBody &ar, const Collider &ac, Transform &bt, RigidBody & br, const Collider &bc, float bounciness = 1);