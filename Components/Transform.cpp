#include "Transform.h"
#include "sfwdraw.h"
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
	sfw::drawCircle(postion.x, postion.y, 12);
	vec2 dirEnd = postion + getDirection()* scale.x;
	vec2 upEnd = postion + perp(getDirection()) * scale.y;

	sfw::drawLine(postion.x, postion.y, dirEnd.x, dirEnd.y, RED);
	sfw::drawLine(postion.x, postion.y, upEnd.x, upEnd.y, BLUE);
}
