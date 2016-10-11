#include "vec3.h"
#include <math.h>

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x , lhs.y - rhs.y , lhs.z - rhs.z};
}

vec3 operator*(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator-(const vec3 & v)
{
	return vec3{ -(v) };
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs = lhs + rhs };
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs = lhs - rhs };
}

vec3 & operator*=(vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs = lhs * rhs };
}

vec3 & operator/=(vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs = lhs / rhs };
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}

vec3 normal(const vec3 & v)
{
	return v / magnitude(v);
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z + rhs.z;
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec3 crossProduct(const vec3 & lhs, const vec3 & rhs)
{
	//a x b = (a^2b^3 - a^3b^2,a^3b^1 - a^1b^3,a^1b^2 - a^2b^1)
	return vec3 {(lhs.y * rhs.z) - (lhs.z * rhs.y), 
				 (lhs.z * rhs.x) - (lhs.x * rhs.z), 
				 (lhs.x * rhs.y) - (lhs.y * rhs.x)};
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}
