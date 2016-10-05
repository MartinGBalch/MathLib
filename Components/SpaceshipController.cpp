#include "SpaceshipController.h"
#include "sfwdraw.h"
using namespace sfw;

SpaceshipController::SpaceshipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;
}

void SpaceshipController::update(spaceShipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= getKey(CTR_LEFT);
	hInput += getKey(CTR_RIGHT);

	float vInput = 0.0f;
	vInput -= getKey(CTR_DOWN);
    vInput += getKey(CTR_UP);

	float bInput = getKey(CTR_BREAK);
	
	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);

}
