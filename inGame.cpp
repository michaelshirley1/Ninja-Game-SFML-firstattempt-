#include "inGame.h"
#include "baseGameStates.h"
#include "sfml.h"
#include "playerMod.h"
#include <iostream>
#include "maps.h"
#include "animation.h"

gameScObj::gameScObj(sf::RenderWindow* window, int * x, int * y, sf::Event* event1) {
	eventz = event1;
	window1 = window;

	sf::Font font1;
	if (!font1.loadFromFile("PIXEAB__.TTF"))
	{
		std::cout << "Nope" << std::endl;
	}

	main1 = new physicObject::player(window1, 300, 10, 0, eventz);
	main2 = new physicObject::player(window1, 400, 10, 1, eventz);
	main3 = new physicObject::player(window1, 500, 10, 2, eventz);
	main4 = new physicObject::player(window1, 600, 10, 3, eventz);

	player1SpriteBack = main1->sprite2;
	player2SpriteBack = main2->sprite2;
	player3SpriteBack = main3->sprite2;
	player4SpriteBack = main4->sprite2;

	player1SpriteBack.setPosition(100, 800);
	player2SpriteBack.setPosition(500, 800);
	player3SpriteBack.setPosition(900, 800);
	player4SpriteBack.setPosition(1300, 800);

	player1SpriteBack.setScale(5, 5);
	player2SpriteBack.setScale(5, 5); 
	player3SpriteBack.setScale(5, 5); 
	player4SpriteBack.setScale(5, 5);
	
	player1HeathText.setString("Okay");
	player1HeathText.setCharacterSize(100);
	player1HeathText.setFont(font1);
	player2HeathText.setString(std::to_string(main2->damage));
	player3HeathText.setString(std::to_string(main3->damage));
	player4HeathText.setString(std::to_string(main4->damage));

	player1HeathText.setPosition(100, 800);
	player2HeathText.setPosition(500, 800);
	player3HeathText.setPosition(900, 800);
	player4HeathText.setPosition(1300, 800);

	player1HeathText.setFillColor(sf::Color::White);
	player2HeathText.setFillColor(sf::Color::White);
	player3HeathText.setFillColor(sf::Color::White);
	player4HeathText.setFillColor(sf::Color::White);


	view1 = window->getDefaultView();
	window->setView(view1);
	shake = false;

	map = new maps::testmap;
	backgroundImage.loadFromFile("backgroundGame1.png");
	backgroundSprite.setTexture(backgroundImage);
	backgroundSprite.scale(6, 6);

	main[0] = main1;
	if (player1) {
		main1->on = true;
	}
	main[1] = main2;
	if (player2) {
		main2->on = true;
	}
	main[2] = main3;
	if (player3) {
		main3->on = true;
	}
	main[3] = main4;
	if (player4) {
		main4->on = true;
	}

	playerCount = *y;
}

void gameScObj::gameLogic() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window1->close();
	}
	main1->updateMovement(window1);
	main2->updateMovement(window1);
	main3->updateMovement(window1);
	main4->updateMovement(window1);
}

void gameScObj::drawGameObj() {
	srand(time(NULL));

	window1->setView(view1);

	gameScObj::window1->clear(sf::Color(255, 255, 255, 40));
	gameScObj::window1->draw(backgroundSprite);

	gameScObj::window1->draw(player1SpriteBack);
	gameScObj::window1->draw(player2SpriteBack);
	gameScObj::window1->draw(player3SpriteBack);
	gameScObj::window1->draw(player4SpriteBack);

	gameScObj::window1->draw(player1HeathText);
	

	collisionDetection();
	
	if (player1 && main1->lives > 0) {
		gameScObj::window1->draw(main1->sprite2);
		if (main1->blocking) {
			gameScObj::window1->draw(main1->blockingSprite);
		}
	}
	if (player2 && main2->lives > 0) {
		gameScObj::window1->draw(main2->sprite2);
		if (main2->blocking) {
			gameScObj::window1->draw(main2->blockingSprite);
		}
	}
	if (player3 && main3->lives > 0) {
		gameScObj::window1->draw(main3->sprite2);
		if (main3->blocking) {
			gameScObj::window1->draw(main3->blockingSprite);
		}
	}
	if (player4 && main4->lives > 0) {
		gameScObj::window1->draw(main4->sprite2);
		if (main4->blocking) {
			gameScObj::window1->draw(main4->blockingSprite);
		}
	}

	if (shake) {
		if (timer.getElapsedTime().asSeconds() < 1.0f) {
			view1.move(float(rand()) / float((RAND_MAX)) * 0.1, -float(rand()) / float((RAND_MAX)) * 0.1);
			view1.move(float(-rand()) / float((RAND_MAX)) * 0.1, -float(rand()) / float((RAND_MAX)) * 0.1);
			view1.move(float(rand()) / float((RAND_MAX)) * 0.1, float(rand()) / float((RAND_MAX)) * 0.1);
			view1.move(float(-rand()) / float((RAND_MAX)) * 0.1, -float(rand()) / float((RAND_MAX)) * 0.1);
			view1.move(float(rand()) / float((RAND_MAX)) * 0.1, -float(rand()) / float((RAND_MAX)) * 0.1);
			view1 = window1->getDefaultView();
		}
		else {
			shake = false;
		}
	}
	
		
	
	

	int i = 0;
	while (i < map->noObj) {
		gameScObj::window1->draw(map->objects[i]->sprite);
		i++;
	}
	
	gameScObj::window1->display();
}

void gameScObj::collisionDetection() {
	map->objects[0]->updateCollisions();
	
	int j = 0;
	while (j < 4) {
		int i = 0;
		int q = 0;
		
		while (q < 4) {
			if (q != j) {
				if (main[j]->sprite2.getGlobalBounds().intersects(main[q]->sprite2.getGlobalBounds()) && main[j]->attackingb) {
					if (main[q]->blocking) {
						main[j]->gotBlocked(main[q]);
					}
					else {
						main[q]->gotHit(main[j]);
					}
					
				}
			}
			q++;
		}
		
		while (i < map->noObj) {
			if (main[j]->sprite2.getGlobalBounds().intersects(map->objects[i]->sprite.getGlobalBounds())) {
				if ((map->objects[i]->y - main[j]->position.y) < 0) {
					main[j]->dirspeedY -= main[j]->dirspeedY - 0.001;
					
				}
				if ((map->objects[i]->y - main[j]->position.y) > 0) {
					main[j]->grounded = true;
					main[j]->dirspeedY -= main[j]->dirspeedY + main[j]->gravity + 0.001;
				}
				//else {
					//if ((map->objects[i]->x - main[j]->position.x) > 2) {
						//main[j]->dirspeedX -= main[j]->dirspeedX + 0.05;
					//}
					//if ((map->objects[i]->x - main[j]->position.x) < 2) {
						//main[j]->dirspeedX += main[j]->dirspeedX + 0.05;
					//}
				//}
			
				
			}

			if (main[j]->sprite2.getPosition().x > 1600 || main[j]->sprite2.getPosition().x < 0 || main[j]->sprite2.getPosition().y > 950 || main[j]->sprite2.getPosition().y < 0) {
				
				main[j]->died();
				
				main[j]->dirspeedX = 0;
				main[j]->dirspeedY = 0;
				
			}
			
			i++;
		}
		j++;
		
	}

	
}
