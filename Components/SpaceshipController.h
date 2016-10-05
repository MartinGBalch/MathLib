#pragma once
#include "spaceShipLocomotion.h"
#include "sfwdraw.h"
using namespace sfw;

class SpaceshipController
{
public:
	
	unsigned   CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(unsigned a_CTR_LEFT = KEY_RIGHT, unsigned a_CTR_RIGHT = KEY_LEFT,
		unsigned a_CTR_UP = KEY_UP, unsigned a_CTR_DOWN = KEY_DOWN,
		unsigned a_CTR_BREAK = ' ');
	void update(spaceShipLocomotion &loco);

};
