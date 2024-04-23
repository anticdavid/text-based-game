#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

int main()
{
	srand(time(0));
	Game* game = new Game(); //creating new game
	game->startGame(); //starting game
	delete game; //deleting pointer
    return 0;
}

