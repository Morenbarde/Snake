#include "Game.h"
#include <iostream>

int main()
{
	//Initialize srand
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	sf::Clock clock;

	while (game.running() && !game.checkCrash()) {
		game.update();
		game.render();
	}

	return 0;
}