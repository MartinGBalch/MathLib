#pragma once

union vec2 
{
	float v[2];
	struct
	{
		float x, y;
	};

	float operator[] (unsigned idx) const;
	float &operator[] (unsigned idx);
};




vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);
vec2 operator/(const vec2 &lhs, float rhs);

vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);


float magnitude(const vec2 &v);

vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 &lhs);

float angleBetween(const vec2 &rhs, const vec2 &lhs);

vec2 perp(const vec2 &v);

float angle(const vec2 &v);

vec2 fromAngle(float a);


vec2 lerp(vec2 &start, vec2 &end, float alpha);

vec2 quadBezier(vec2 &a_A, vec2 &a_B, vec2 a_C, float a_t);

vec2 hermitspline(vec2 &point0, vec2 &point1, vec2 &tangent0, vec2 &tangent1, float t);

vec2 cardinalSpline(vec2 &point0, vec2 &point1, vec2 &point2, vec2 &a, float t);

vec2 catRomSpline(vec2 &point0, vec2 &point1, vec2 &point2, float t);

vec2 min(const vec2 &A, const vec2 &B);
vec2 max(const vec2 &A, const vec2 &B);

vec2 project(vec2 o, vec2 n);
vec2 reflect(vec2 o, vec2 n);
