#include "SpaceshipRenderer.h"
#include "sfwdraw.h"
#include "shapedraw.h"
using namespace sfw;

ShipRenderer::ShipRenderer()
{
	color = RED;
}

void ShipRenderer::draw(Transform & ship, const mat3 & T)
{
	mat3 glob = T * ship.getGlobalTransform();

	//drawAABB(glob * AABB{ 0,.5f, .5,.75f}, BLUE);
	

	vec3 A = glob * vec3{  0, 2, 1 };
	vec3 B = glob * vec3{  1,-1, 1 };
	vec3 C = glob * vec3{ -1,-1, 1 };
	//vec3 D = glob * vec3{  -1,1, 1 };

	//drawLine(A.x, A.y, B.x, B.y, color);
	//(B.x, B.y, C.x, C.y, color);
	//drawLine(C.x, C.y, A.x, A.y, color);
	//drawLine(D.x, D.y, A.x, A.y, color);

	drawPlane(glob * Plane{ 0,0,1,0 }, WHITE);
	
}
