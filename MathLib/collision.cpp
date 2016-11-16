#include "collision.h"
#include <cstdio>
#include <cmath>

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pdr = Amax - Bmin;
	float pdl = Bmax - Amin;
	float small;

	if (pdr > pdl)
	{
		small = pdl;
		retval.collisionNormal = -1;
	}
	else
	{
		small = pdr;
		retval.collisionNormal = 1;
	}

	retval.penetrationDepth = small;

	/*float G = (Amax - Bmin) - (Bmax - Amin);
	float One;

	if (G > 0)
	{
		One = 1;
	}
	else {One = -1;}

	retval.collisionNormal = One;
*/
	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;
	float tl = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.collisionNormal = copysignf(1, tl - tr);
		
	if (tl > tr)
	{
		retval.entryTime = tr;
		retval.exitTime = tl;
	}
	else
	{
		retval.entryTime = tl;
		retval.exitTime = tr;
	}
	return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D YCD = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *YCD.collisionNormal;
	}

	return retval;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	// Discrete results in case there is no movement along the axis.
	CollisionData1D Xdis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Ydis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);

	// Swept results along each axis
	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x,
		B.min().x, B.max().x, dB.x);

	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y,
		B.min().y, B.max().y, dB.y);
	// whether or not to use swept along that axis.
	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);


	// if x is sweeping and happens latest OR y is not sweeping
	if (Yres.entryTime < Xres.entryTime || xSwept && !ySwept)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;

		retval.collides = ySwept || Ydis.result();
	}
	else if (ySwept)
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
		retval.collides = xSwept || Xdis.result();
	}

	if (Yres.exitTime < Xres.exitTime || ySwept && !xSwept)

		retval.exitTime = Yres.exitTime;
	else if (xSwept)
		retval.exitTime = Xres.exitTime;

	return retval;
}

CollisionData planeBoxCollision(const Plane & P, const AABB & B)
{
	CollisionData retval;
	vec2 BL{ B.min().x, B.min().y },
		 BR{ B.max().x, B.min().y },
		 TL{ B.min().x, B.max().y },
		 TR{ B.max().x, B.max().y };

	float PMAX = dot(P.dir, P.pos);

	float FTR = dot(P.dir, TR);
	float FTL = dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float Amin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float Amax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.penetrationDepth = PMAX - Amin;
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const AABB & B, const vec2 & bA)
{
	CollisionDataSwept retval;

	vec2 BL{ B.min().x, B.min().y },
		 BR{ B.max().x, B.min().y },
		 TL{ B.min().x, B.max().y },
		 TR{ B.max().x, B.max().y };

	float PMAX = dot(P.dir, P.pos);

	float Bvel = dot(P.dir, bA);

	float FTR = dot(P.dir, TR);
	float FTL = dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float Amin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float Amax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.entryTime = (Amin - PMAX) / (0 - Bvel);
	retval.exitTime = (Amax - PMAX) / (0 - Bvel);

	retval.collisionNormal = P.dir;

	return retval;
}

CollisionData HullCollision(const Hull & A, const Hull & B)
{
	int size = 0;
	vec2 axes[32];
	//comb all the axes into a single array
	for (int j = 0; j < A.size; ++j){axes[size++] = A.normals[j];}
	for (int j = 0; j < B.size; ++j){axes[size++] = B.normals[j];}

	CollisionData retval;
	retval.penetrationDepth = INFINITY;
	// For every axis,
	for (int j = 0; j < size; j++)
	{
		vec2 &axis = axes[j];
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;
		
		//Project points onto the axis.
		amin = A.min(axis);
		amax = A.max(axis);

		bmin = B.min(axis);
		bmax = B.max(axis);

		float pDr, pDl, pD;
		pDr = amax - bmin;
		pDl = bmax - amin;

		pD = fminf(pDr, pDl);
		float H = copysignf(1, pDl - pDr);

		if (pD < retval.penetrationDepth)
		{
			retval.penetrationDepth = pD;
			retval.collisionNormal = axis * H;
		}
	}


	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}
