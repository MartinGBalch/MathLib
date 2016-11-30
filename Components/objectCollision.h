#pragma once

#include "Astroids.h"
#include "PlayerShip.h"
#include "GravBullet.h"
#include "TractorBeam.h"
#include "Target.h"

/*
These are interactions between objects.
In general, they occur on collision, but they can be as specialized
or do whatever you want them to.
Each time you introduce a new game object, you may want to create a
custom interaction between that object and another object.
*/

void PlayerAstroidCollision(PlayerShip &player, Astroid &as);

void AstroidCollision(Astroid &as1, Astroid &as2);

void targetAstroidCollision(Target &t, Astroid &a);


void BulletAsteroidCollision(GravBullet &bullet, Astroid &asteroid);

void TractorBulletCollision(TractorBeam &tractor, GravBullet &bullet);