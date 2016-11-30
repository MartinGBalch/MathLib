#include "ObjectCollision.h"
#include <iostream>


void PlayerAstroidCollision(PlayerShip & player, Astroid & as)
{
	CollisionData result =
		//DynamicResolution(player.transform, player.rigidbody, player.collider,
			//as.transform, as.rigidbody, as.collider);

		StaticResolution(as.transform, as.rigidbody, as.collider, player.transform, player.collider, .5f);


	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		vec2 dir = normal(player.transform.getGlobalPosition() -
			as.transform.getGlobalPosition());

		player.transform.m_scale *= 1.f;
		
	}
}

void AstroidCollision(Astroid & as1, Astroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void targetAstroidCollision(Target & t, Astroid & a)
{
	
	CollisionData result = StaticResolution(a.transform, a.rigidbody, a.collider, t.trans, t.collider, .31f);
	
	if (result.penetrationDepth >=0)
	{
		//t.trans.m_scale *= .5f;
		t.hp -= 1.f;
	}
	if (t.hp >= 375) { t.color = WHITE; }
	else if( t.hp >= 185 ) {t.color = MAGENTA;}
	else { t.color = RED; }
	
}

void BulletAsteroidCollision(GravBullet &b, Astroid &a)
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
    a.rigidbody.addImpulse(dir * 200);
			   
	if (b.timer <= 0)
	{
		a.rigidbody.drag *= 200;
		
		
	}

	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		b.isAlive = false;
		
		
	}
}


void TractorBulletCollision(TractorBeam & tractor, GravBullet &bullet)
{
	// Make sure the tractor is active!
	if (!tractor.isAlive) return;

	// We don't use resolution-- the tractor is non-physical!
	// Just want to know if the asteroid is in the beam.
	CollisionData result =
		ColliderCollision(tractor.transform, tractor.collider,
			bullet.transform, bullet.collider);

	// if it is
	if (result.penetrationDepth >= 0)
	{
		// find the direction between
		vec2 dir = normal(tractor.transform.getGlobalPosition() -
			bullet.transform.getGlobalPosition());
		// and add a force to pull the objet toward us.
		bullet.rigidbody.addImpulse(dir * 5);
		// If we flip the force, we can push stuff away.
	}
}