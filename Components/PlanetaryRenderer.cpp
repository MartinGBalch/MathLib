#include "PlanetaryRenderer.h"
#include "sfwdraw.h"
#include "vec3.h"
using namespace sfw;

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(Transform & planetTrans, const mat3& T)
{
	mat3 glob = T * planetTrans.getGlobalTransform();

	//right (x direction), up (y direction), position
	float xRad = magnitude(glob * vec3{ size,0,0 });
	float yRad = magnitude(glob * vec3{ 0,size,0 });

	vec2 pos = glob[2].xy;

	float rad = xRad > yRad ? xRad : yRad;

	drawCircle(pos.x, pos.y, size, 12U, color);
}
