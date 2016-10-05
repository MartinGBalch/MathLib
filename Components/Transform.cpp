#include "Transform.h"
#include "sfwdraw.h"
#include <cmath>
#include <cstdio>
using namespace sfw;

Transform::Transform(float x, float y, float w, float h, float a) 
{
	position.x = x;
	position.y = y;
	
	scale.x = w;
	scale.y = h;

	facing = a;
}

vec2 Transform::getDirection() const
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

	
	
	

}
