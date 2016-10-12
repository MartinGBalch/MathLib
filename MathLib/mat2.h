#pragma once
#include "vec2.h"

union mat2
{
	float m[4];      // single dimensional array
	float mm[2][2];  // mutidimensional array
	vec2 c[2];       // column vectors
	vec2 operator[] (unsigned idx) const;
	vec2 &operator[](unsigned idx);

};

mat2 mat2Identity();
mat2 transpose(const mat2 &A);

// Matrix addition
mat2 operator+(const mat2 &A, const mat2 &B);

// Matrix subtraction
mat2 operator-(const mat2 &A, const mat2 &B);

// matrix negative
mat2 operator-(const mat2 &V);

//mat2 == mat2 : equivalence
bool operator==(const mat2 &A, const mat2 &B);
bool operator!=(const mat2 &A, const mat2 &B);

mat2 operator*(const mat2 &A, float B);
mat2 operator*(float A, const mat2 &B);
mat2 operator*(const mat2 &A, const mat2 &B);
vec2 operator*(const mat2 &A, const vec2 &V);

float determinate(const mat2 &d);
mat2 inverse(const mat2 &v);


