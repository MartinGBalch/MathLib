#include "mat3.h"

vec3 mat3::operator[](unsigned idx) const
{
	return vec3();
}

vec3 & mat3::operator[](unsigned idx)
{
	// TODO: insert return statement here
}

mat3 mat3Identity()
{
	return mat3();
}

mat3 transpose(const mat3 & A)
{
	return mat3();
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator-(const mat3 & V)
{
	return mat3();
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return false;
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return false;
}

mat3 operator*(const mat3 & A, float B)
{
	return mat3();
}

mat3 operator*(float A, const mat3 & B)
{
	return mat3();
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator*(const mat3 & A, const vec3 & V)
{
	return mat3();
}

float determinate(const mat3 & d)
{
	return 0.0f;
}

mat3 inverse(const mat3 & v)
{
	return mat3();
}
