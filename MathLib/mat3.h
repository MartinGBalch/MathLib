#pragma once
#include "vec3.h"

union mat3
{
	float m[9];      // single dimensional array
	float mm[3][3];  // mutidimensional array
	vec3 c[3];       // column vectors
	vec3 operator[] (unsigned idx) const;
	vec3 &operator[](unsigned idx);

};

mat3 mat3Identity();
mat3 transpose(const mat3 &A);

// Matrix addition
mat3 operator+(const mat3 &A, const mat3 &B);

// Matrix subtraction
mat3 operator-(const mat3 &A, const mat3 &B);

// matrix negative
mat3 operator-(const mat3 &V);

//mat3 == mat3 : equivalence
bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, float B);
mat3 operator*(float A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const vec3 &V);

float determinate(const mat3 &d);
mat3 inverse(const mat3 &v);
