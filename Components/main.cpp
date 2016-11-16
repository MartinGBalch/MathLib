#include "sfwdraw.h"
#include "GameState.h"

#include <cstdio>

void main()
{
	float SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	setBackgroundColor(BLACK);

	GameState game;

	game.play();

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		game.update(dt);

		game.draw();

	}
	sfw::termContext();
}