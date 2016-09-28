#include "sfwdraw.h"
#include "vec2.h"
#include <cstdio>
#include "Transform.h"

void main()
{
	sfw::initContext();
	//Transform trans;
	Transform trans = Transform(400, 300);
	//Transform trans(400, 300);
	sfw::setBackgroundColor(BLACK);

	/*trans.postion = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 12,8 };*/
	while (sfw::stepContext())
	{
		trans.debugDraw();
	}

	sfw::termContext();
}