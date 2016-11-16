#include "shapes.h"
#include "flops.h"

#include <cmath>

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T * vec3{ C.pos.x, C.pos.y, 1 }).xy;


	
	float mX = magnitude(T * vec3{ C.rad, 0,0 });
	float mY = magnitude(T * vec3{ 0, C.rad,0 });

	retval.rad = mX > mY ? mX : mY;

	return retval;
	
}

bool operator==(const Circle & A, const Circle & B)
{
	
	return A.pos == B.pos	 && fequals(A.rad, B.rad);
}

AABB operator*(const mat3 & T, const AABB & A)
{
	AABB retval = A;

	vec3 a = (T * vec3{ A.min().x,A.min().y, 1 });
	vec3 b = (T * vec3{ A.min().x,A.max().y, 1 });
	vec3 c = (T * vec3{ A.max().x,A.min().y, 1 });
	vec3 d = (T * vec3{ A.max().x,A.max().y, 1 });

	float posx = (a.x + b.x + c.x + d.x) /4;
	float posy = (a.y + b.y + c.y + d.y) /4;
	retval.pos = (vec3{ posx, posy,1 }).xy;

	float greatestX;
	float greatestY;
	float smallestX;
	float smallestY;

	if (a.x <= b.x && a.x <= c.x && a.x <= d.x)
	{
		smallestX = a.x;
	}
	else if (b.x <= a.x && b.x <= c.x && b.x <= d.x)
	{
		smallestX = b.x;
	}
	else if (c.x <= a.x && c.x <= b.x && c.x <= d.x)
	{
		smallestX = c.x;
	}
	else
	{
		smallestX = d.x;
	}

	if (a.x >= b.x && a.x >= c.x && a.x >= d.x)
	{
		greatestX = a.x;
	}
	else if (b.x >= a.x && b.x >= c.x && b.x >= d.x)
	{
		greatestX = b.x;
	}
	else if (c.x >= a.x && c.x >= b.x && c.x >= d.x)
	{
		greatestX = c.x;
	}
	else
	{
		greatestX = d.x;
	}

	if (a.y <= b.y && a.y <= c.y && a.y <= d.y)
	{
		smallestY = a.y;
	}
	else if (b.y <= a.y && b.y <= c.y && b.y <= d.y)
	{
		smallestY = b.y;
	}
	else if (c.y <= a.y && c.y <= b.y && c.y <= d.y)
	{
		smallestY = c.y;
	}
	else
	{
		smallestY = d.y;
	}

	if (a.y >= b.y && a.y >= c.y && a.y >= d.y)
	{
		greatestY = a.y;
	}
	else if (b.y >= a.y && b.y >= c.y && b.y >= d.y)
	{
		greatestY = b.y;
	}
	else if (c.y >= a.y && c.y >= b.y && c.y >= d.y)
	{
		greatestY = c.y;
	}
	else
	{
		greatestY = d.y;
	}

	float halfX = (greatestX - smallestX);
	float halfY = (greatestY - smallestY);

	retval.he = { halfX, halfY };
	return retval;
}


Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;
	retval.dir = normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;
	return retval;
}

bool operator==(const Plane & A, const Plane & B)
{
	return A.pos == B.pos && A.dir == B.dir;
}

Hull operator*(const mat3 & T, const Hull & P)
{
	Hull retval;
	retval.size = P.size;
	for (int i = 0; i < P.size; ++i)
	{
		retval.vertices[i] = (T *vec3{ P.vertices[i].x, P.vertices[i].y, 1 }).xy;
		retval.normals[i] = normal((T *vec3{ P.normals[i].x, P.normals[i].y, 0 }).xy);
	}
	return retval;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

Hull::Hull()
{
	//position = { 0,0 };
	size = 0;
}

float Hull::min(const vec2 & axis) const
{
	float amin = INFINITY;

	for (int i = 0; i < size; ++i)
		amin = fminf(dot(axis, vertices[i]), amin);

	return amin;
}

float Hull::max(const vec2 & axis) const
{
	float amax = -INFINITY;
	for (int i = 0; i < size; ++i)
		amax = fmaxf(dot(axis, vertices[i]), amax);
	return amax;
}

Hull::Hull(const vec2 * a_vertices, unsigned vsize)
{
	size = vsize;
	for (int i = 0; i < vsize; i++)
	{
		vertices[i] = a_vertices[i];
		normals[i] = -perp(normal(a_vertices[(i+1)%size] - a_vertices[i]));
	}
}
