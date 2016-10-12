#include "mat3.h"
#include "flops.h"
#include <cmath>

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

mat3 mat3Identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
	             0,0,1};
}

mat3 transpose(const mat3 & A)
{
	mat3 temp = A;
	temp.m[0] = temp.m[0];
	temp.m[1] = temp.m[3];
	temp.m[2] = temp.m[6];
	temp.m[3] = temp.m[1];
	temp.m[4] = temp.m[4];
	temp.m[5] = temp.m[7];
	temp.m[6] = temp.m[2];
	temp.m[7] = temp.m[5];
	temp.m[8] = temp.m[8];

	return A;
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0],
				 A.m[1] + B.m[1],
			     A.m[2] + B.m[2],
			     A.m[3] + B.m[3],
				 A.m[4] + B.m[4],
				 A.m[5] + B.m[5],
				 A.m[6] + B.m[6],
				 A.m[7] + B.m[7],
				 A.m[8] + B.m[8]};
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0],
				 A.m[1] - B.m[1],
				 A.m[2] - B.m[2],
				 A.m[3] - B.m[3],
				 A.m[4] - B.m[4],
				 A.m[5] - B.m[5],
				 A.m[6] - B.m[6],
				 A.m[7] - B.m[7],
				 A.m[8] - B.m[8]};

}

mat3 operator-(const mat3 & V)
{
	return mat3{ -V.m[0], -V.m[1], -V.m[2], -V.m[3], -V.m[4],
				 -V.m[5], -V.m[6], -V.m[7], -V.m[8]};
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		   fequals(A.m[1], B.m[1]) &&
		   fequals(A.m[2], B.m[2]) &&
		   fequals(A.m[3], B.m[3]) &&
		   fequals(A.m[4], B.m[4]) &&
		   fequals(A.m[5], B.m[5]) &&
		   fequals(A.m[6], B.m[6]) &&
		   fequals(A.m[7], B.m[7]) &&
		   fequals(A.m[8], B.m[8]);
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return !(A == B);
}

mat3 operator*(const mat3 & A, float B)
{
	return mat3{ A.m[0] * B, A.m[1] * B, A.m[2] * B, A.m[3] * B,
		         A.m[4] * B, A.m[5] * B, A.m[6] * B, A.m[7] * B, A.m[8] * B};
}

mat3 operator*(float A, const mat3 & B)
{
	return mat3{ B.m[0] * A, B.m[1] * A, B.m[2] * A, B.m[3] * A,
		         B.m[4] * A, B.m[5] * A, B.m[6] * A, B.m[7] * A, B.m[8] * A };
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return{ ((A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2])),
			((A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2])),
			((A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2])),

			((A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5])),
			((A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5])),
			((A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5])),

			((A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8])),			
			((A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8])),
			((A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8])) };
}

vec3 operator*(const mat3 & A, const vec3 & V)
{
	return{ ((A.m[0] * V.x) + (A.m[3] * V.x) + (A.m[6] * V.z)),
			((A.m[1] * V.x) + (A.m[4] * V.x) + (A.m[7] * V.z)),
			((A.m[2] * V.x) + (A.m[5] * V.x) + (A.m[8] * V.z))};
}

float determinate(const mat3 & d)
{
	return float (d.m[0] * d.m[4] * d.m[8]) + 
				 (d.m[3] * d.m[7] * d.m[2]) +
				 (d.m[6] * d.m[1] * d.m[5]) - 
		         (d.m[6] * d.m[4] * d.m[2]) -
				 (d.m[3] * d.m[1] * d.m[8]) - 
				 (d.m[0] * d.m[7] * d.m[5]) ;
}

mat3 inverse(const mat3 & v)
{
	
	return (1 / (determinate(v)) * transpose(v));
}

mat3 scale(float w, float h)
{
	return{ { w,0,0,
			  0,h,0,
			  0,0,1} };
}

mat3 translate(float x, float y)
{
	return{ { 1,0,0,
			  0,1,0,
			  x,y,1} };
}

mat3 rotation(float a)
{
	return{ {cos(a), sin(a), 0,
			 -sin(a),  cos(a), 0,
			      0,       0, 1  } };
}

