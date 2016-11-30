#include "Target.h"
#include "sfwdraw.h"
#include "GameState.h"

Target::Target()
{ 
	 hp = 375;
	 color = WHITE;
	vec2 hullVrts[] = { { -1,0 },{ -1,2 },{ 1,2 }, {1,0} };
	collider = Collider(hullVrts, 4);

	trans.m_scale = vec2{ 75,75 };
	rigid.mass = 10;
}

void Target::update(float deltaTime, GameState & gs)
{
	

	

	rigid.integrate(trans, deltaTime);
}

void Target::draw(const mat3 & camera)
{
	collider.DebugDraw(camera, trans, color);
}
