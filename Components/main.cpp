#include "sfwdraw.h"
#include "vec2.h"
#include <cstdio>
#include "Transform.h"
#include "flops.h"
using namespace sfw;

void main()
{
	sfw::initContext(800,800);
	
	sfw::setBackgroundColor(BLACK);

	

	
	while (sfw::stepContext())
	{
		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = growFast(x1);
			float y2 = growFast(x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 800;
			y2 *= 800;

			drawLine(x1,y1, x2,y2);
		}
	}

	sfw::termContext();
}