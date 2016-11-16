#include "shapedraw.h"
#include "sfwdraw.h"
#include "Transform.h"
using namespace sfw;

void drawCircle(const Circle & c, unsigned color)
{
	drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	

	drawLine(B.min().x, B.min().y, B.min().x, B.max().y, color);
	drawLine(B.min().x, B.min().y, B.max().x, B.min().y, color);
	drawLine(B.max().x, B.max().y, B.max().x, B.min().y, color);
	drawLine(B.min().x, B.max().y, B.max().x, B.max().y, color);
}

void drawPlane(const Plane & A, unsigned color)
{
	drawLine(A.pos.x, A.pos.y,(A.dir.x * 60 + A.pos.x ), (A.dir.y * 60 + A.pos.y) , color);
	drawLine(A.pos.x, A.pos.y, (A.pos.x - A.dir.x * 60 ), (A.pos.y - A.dir.y * 60) , color);
}

void drawHull(const Hull & h, unsigned color)
{
	for (int i = 0; i < h.size && i < 16; ++i)
	{
		drawLine(h.vertices[i].x, h.vertices[i].y,
				 h.vertices[(i + 1) % h.size].x,
				 h.vertices[(i + 1) % h.size].y, color);
		
	}
}
