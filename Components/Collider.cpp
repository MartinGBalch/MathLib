#include "Collider.h"
#include "sfwdraw.h"
#include "shapedraw.h"
#include <cmath>


Collider::Collider()
{
}

Collider::Collider(const vec2 * verts, int size) : hull(verts, size)
{
	vec2 boxMin = { INFINITY,  INFINITY },
		boxMax = { -INFINITY, -INFINITY };

	for (int i = 0; i < size; ++i)
	{
		boxMin = min(boxMin, verts[i]);
		boxMax = max(boxMax, verts[i]);
	}

	box.pos = (boxMin + boxMax) / 2;
	box.he = (boxMax - boxMin) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans, unsigned int color)
{

	// Draw the AABB
		// Already have a draw AABB function
	drawAABB(T * trans.getGlobalTransform() * box, NONE);
	drawHull(T * trans.getGlobalTransform() * hull, color);

	// Draw convex hull
		// need a drawing function for hulls

}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData retval;

	// broad phase
	// are the boxes in collision?
	retval = boxCollision(AT.getGlobalTransform() * AC.box,
				 BT.getGlobalTransform() * BC.box);

	// narrow phase
	if (retval.penetrationDepth >= 0 )
	{
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
							   BT.getGlobalTransform() * BC.hull);
	}
	

	return retval;
}

CollisionData StaticResolution(Transform & at, RigidBody & ar, const Collider & ac, const Transform & bt, const Collider & bc, float bounciness)
{
	CollisionData results = ColliderCollision(at, ac, bt,bc);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		at.m_position -= MTV;

		ar.velocity = reflect(ar.velocity, results.collisionNormal) * bounciness;
	}

	return results;
}

CollisionData DynamicResolution(Transform & at, RigidBody & ar, const Collider & ac,  Transform & bt, RigidBody & br, const Collider & bc, float bounciness)
{
	CollisionData results = ColliderCollision(at, ac, bt, bc);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(ar.mass * ar.velocity);
		float bm = magnitude(br.mass * br.velocity);
		float cm = am + bm;

		at.m_position -= MTV  *(1 - am / cm);
		bt.m_position += MTV * (1 - bm / cm);

		vec2  A = ar.velocity;		// Velocity for A
		float P = ar.mass;			// Mass for A
		vec2  X;					// final velocity for A

		vec2  B = br.velocity;		// Velocity for B
		float Q = br.mass;			// mass for B
		vec2  Y;					// final velocity for Y

		float E = bounciness;		// coefficient of restitution

									//// Solve the system of linear equations!
									//A * P + B * Q = X * P + Y * Q   : conservation of momentum
									//X - Y = -E(A - B)    			  : linear collision

		X = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);
		Y = E*(A - B) + X;

		ar.velocity = X;
		br.velocity = Y;
	}

	return results;
}
