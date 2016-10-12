#pragma once

#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);
	vec2 m_position;
	vec2 m_scale;
	float m_facing;

	

	bool tick = false;

	vec2 getUp() const;
	vec2 getDirection() const;
	mat3 getLocalTransform() const;
	void setDirection(const vec2 &dir);

	void debugDraw(const mat3 &T = mat3Identity()) const;
};