#pragma once

#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	//Transform();
	
	vec2 m_position;
	vec2 m_scale;
	float m_facing;

	Transform *m_parent;

	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);

	
	bool tick = false;

	vec2 getUp() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);

	vec2 getGlobalPosition() const;
	vec2 getGlobalright() const;
	vec2 getGlobalup() const;
	float getGlobalAngle() const;


	mat3 getGlobalTransform() const;
	mat3 getLocalTransform() const;


	

	void debugDraw(const mat3 &T = mat3Identity()) const;
};