#include "SpaceshipRenderer.h"
#include "sfwdraw.h"
using namespace sfw;

ShipRenderer::ShipRenderer()
{
	color = MAGENTA;
}

void ShipRenderer::draw(Transform & ship, const mat3 & T)
{
	mat3 glob = T * ship.getGlobalTransform();

	vec3 F = glob * vec3{  0, 2, 1 };
	vec3 L = glob * vec3{ -1,-1,-1 };
	vec3 R = glob * vec3{  1,-1, 1 };

	drawLine(L.x, L.y, F.x, F.y, color);
	drawLine(F.x, F.y, R.x, R.y, color);
	drawLine(R.x, R.y, L.x, L.y, color);
}
