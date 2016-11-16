#include "ObjectCollision.h"


void PlayerAstroidCollision(PlayerShip & player, Astroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		player.transform.m_scale *= 1.f;
	}
}

void AstroidCollision(Astroid & as1, Astroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidCollision(GravBullet &b, Astroid &a, TractorBeam &tractor)
{
	// make sure the bullet is active!
	if (!b.isAlive) return;

	// Use dynamic resolution, so the bullet bumps stuff away.
	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);
	/*CollisionData result =
		ColliderCollision(tractor.transform, tractor.collider,
			a.transform, a.collider);
*/
	vec2 dir = normal(b.transform.getGlobalPosition() -
			   a.transform.getGlobalPosition());
    a.rigidbody.addForce(dir * 5000);
			   
	if (b.timer <= 0)
	{
		a.rigidbody.drag = 10.f;
		a.rigidbody.addForce(dir * -5000);
	}

	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		b.timer = 0;
		
		
	}
}


void TractorAsteroidCollision(TractorBeam & tractor, Astroid & asteroid)
{
	// Make sure the tractor is active!
	if (!tractor.isAlive) return;

	// We don't use resolution-- the tractor is non-physical!
	// Just want to know if the asteroid is in the beam.
	CollisionData result =
		ColliderCollision(tractor.transform, tractor.collider,
			asteroid.transform, asteroid.collider);

	// if it is
	if (result.penetrationDepth >= 0)
	{
		// find the direction between
		vec2 dir = normal(tractor.transform.getGlobalPosition() -
			asteroid.transform.getGlobalPosition());
		// and add a force to pull the objet toward us.
		asteroid.rigidbody.addForce(dir * 500);
		// If we flip the force, we can push stuff away.
	}
}