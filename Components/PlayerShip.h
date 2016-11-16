#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "spaceShipLocomotion.h"

class PlayerShip
{
public:
	Transform transform;
	Collider collider;
	RigidBody rigidbody;
	SpaceshipController controller;
	spaceShipLocomotion motion;

	PlayerShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);

};