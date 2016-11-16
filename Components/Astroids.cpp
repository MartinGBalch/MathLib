#include "Astroids.h"

Astroid::Astroid()
{
	vec2 hullVrts[] = { {-1,0},{0,1},{1,0} };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 12,12 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Astroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Astroid::draw(const mat3 & camera)
{
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
}
