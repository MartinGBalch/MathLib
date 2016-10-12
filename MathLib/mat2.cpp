#include "mat2.h"
#include "flops.h"

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}

mat2 transpose(const mat2 & A)
{
	mat2 retval = A;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2 { A.m[0] + B.m[0], 
				  A.m[1] + B.m[1],
				  A.m[2] + B.m[2], 
				  A.m[3] + B.m[3]};
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0],
				 A.m[1] - B.m[1],
				 A.m[2] - B.m[2],
				 A.m[3] - B.m[3]};
}

mat2 operator-(const mat2 & V)
{
	return mat2{ -V.m[0], -V.m[1], -V.m[2], -V.m[3] };
}

bool operator==(const mat2 & A, const mat2 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		   fequals(A.m[1], B.m[1]) &&
		   fequals(A.m[2], B.m[2]) &&
		   fequals(A.m[3], B.m[3]);
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return !fequals(A.m[0], B.m[0]) &&
		   !fequals(A.m[1], B.m[1]) &&
		   !fequals(A.m[2], B.m[2]) &&
		   !fequals(A.m[3], B.m[3]);
}

mat2 operator*(const mat2 & A, float B)
{
	return mat2{ A.m[0] * B, A.m[1] * B, A.m[2] * B, A.m[3] * B };
}

mat2 operator*(float A, const mat2 & B)
{
	return mat2{ B.m[0] * A, B.m[1] * A, B.m[2] * A, B.m[3] * A };
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	return{ A.m[0] * B.m[0] + A.m[2] * B.m[1],
			A.m[0] * B.m[2] + A.m[2] * B.m[3],
			A.m[1] * B.m[0] + A.m[3] * B.m[2],
		    A.m[1] * B.m[2] + A.m[3] * B.m[3]};
}

vec2 operator*(const mat2 & A, const vec2 & V)
{
	return vec2{ (A.m[0] * V.x) + (A.m[1] * V.y), 
				 (A.m[2] * V.x) + (A.m[3] * V.y) };
}

float determinate(const mat2 & d)
{
	return float (d.m[0] * d.m[3]) - (d.m[1] * d.m[2]);
}

mat2 inverse(const mat2 & v)
{
	return (1 / (determinate(v)) * mat2 { v.m[3], -v.m[1], -v.m[2], v.m[0] });
}
