#pragma once
#include "vec2.h"
#include "shapes.h"
struct CollisionData1D
{
	//bool result;
	float penetrationDepth;// how much overlap
	float collisionNormal;// -1 or 1
	//float MTV;//penetrationDepth * collisionNormal

	bool result() const;
	float MTV() const;
};

CollisionData1D collisionDetection1D(float Amin, float Amax, 
									float Bmin, float Bmax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;
};

// pos
// pos + vel * deltaTime
// displacement = vel * deltaTime
SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A, const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;
	bool collides;
	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
								const AABB &B, const vec2 &dB);

//Determine the 4 points on the box
//project them onto the planes axis
//find the minimum and maximum along the axis
// perform 1D SAT discrete detection

CollisionData planeBoxCollision(const Plane &P, const AABB &B);

CollisionDataSwept planeBoxCollisionSwept(const Plane &P, const AABB &B, const vec2 &bA);

CollisionData HullCollision(const Hull &A, const Hull &B);