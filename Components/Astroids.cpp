#include "Astroids.h"
#include "sfwdraw.h"

Astroid::Astroid()
{
	vec2 hullVrts[] = { {-1,0},{0,1},{1,0} };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 15,15 };
	rigidbody.drag = 10.0f;
	rigidbody.angularDrag = 1.0f;
	rigidbody.mass = 10;
	//slowdown = 10.0f;
}

void Astroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Astroid::draw(const mat3 & camera)
{
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform, RED);
	//rigidbody.debugDraw(camera, transform);
}

//void Astroid::getSlow(float value) { slowdown += value; }
