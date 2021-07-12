
#include "baseGameStates.h"
#include "sfml.h"
#include "inGame.h"
#include <iostream>
#include "animation.h"
#include "inTitle.h"

gameStates gameState;

//Window Handler
int main()
{
	int gameState1 = 0;
	int playerCount = 1;
	sf::Event event;
	
	sf::RenderWindow window(sf::VideoMode(1600, 950), "Ninja Guys");
	inTitle* title = new inTitle(&window, &gameState1, &playerCount, &event);
	gameScObj* game = new gameScObj(&window, &gameState1, &playerCount, &event);
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		if (gameState1 == 0) {
			title->titleLogic();
			if (title->state == 1) {
				playerCount = title->k;
				std::cout << playerCount;
				game = new gameScObj(&window, &gameState1, &playerCount, &event);
				game->player1 = title->player1;
				game->player2 = title->player2;
				game->player3 = title->player3;
				game->player4 = title->player4;
				gameState1 = 1;
				
			}
		}
		
		if (gameState1 == 1) {
			game->gameLogic();
			game->drawGameObj();
		}

	}
	return 0;
}