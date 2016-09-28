#include "Transform.h"
#include "sfwdraw.h"
#include <cmath>
#include <cstdio>
using namespace sfw;
Transform::Transform() : facing(0), position({0,0}), scale({28,8})
{
	/*position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 8;

	facing = 0;*/
}
Transform::Transform(float x, float y) : Transform()
{
	position.x = x;
	position.y = y;


}
vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y,12,12,GREEN);
	vec2 dirEnd = position + getDirection()* 20;
	vec2 dirEnd2 = position - getDirection() * 20;
	vec2 upEnd = position + perp(getDirection()) * 20;
	vec2 upEnd2 = position - perp(getDirection()) * 20;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y,RED );
	sfw::drawLine(position.x, position.y, dirEnd2.x, dirEnd2.y, RED);
	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, RED);
	sfw::drawLine(position.x, position.y, upEnd2.x, upEnd2.y, RED);

	
	if (getKey(KEY_UP))
	{
		position += getDirection() * 5;
	}
	else if (getKey(KEY_DOWN))
	{
		position -= getDirection() * 5;
	}
	if (getKey(KEY_RIGHT))
	{
		facing -= .1;
	}
	else if (getKey(KEY_LEFT))
	{
		facing += .1;
	}
	if (position.x >= 800)
	{
		position.x = 0;
	}
	else if (position.x <= 0)
	{
		position.x = 800;
	}
	else if (position.y >= 600)
	{
		position.y = 0;
	}
	else if (position.y <= 0)
	{
		position.y = 600;
	}

}
