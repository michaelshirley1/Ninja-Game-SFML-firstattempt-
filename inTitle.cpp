#include "sfml.h"
#include "baseGameStates.h"
#include "playerMod.h"
#include "collision.h"
#include "maps.h"
#include "inTitle.h"
#include <iostream>

inTitle::inTitle(sf::RenderWindow* window, int * x, int * y, sf::Event* event1){
	single = false;
	multi = false;
	characterselectsingle = false;
	player1 = true;
	player2 = false;
	player3 = false;
	player4 = false;

	window1 = window;
	events = event1;
	state = 0;
	pressed = false;
	clock.restart();
	window1->setKeyRepeatEnabled(false);

	titleBackground.loadFromFile("titleBackground.png");
	titleLogo.loadFromFile("ninjaguyslogo.png");
	selection.loadFromFile("selection.png");
	singleLogo.loadFromFile("singleplayerlogo.png");
	multiLogo.loadFromFile("multiplayerlogo.png");
	if (!character.loadFromFile("characterSelect.png")) {
		std::cout << "failedtoload";
	}
	
	
	borderSprite1.setTexture(character);
	borderSprite1.setTextureRect(sf::IntRect(0, 0,100, 100));
	characterSprite1.setTexture(character);
	characterSprite1.setTextureRect(sf::IntRect(100, 0, 100, 100));
	borderSprite2.setTexture(character);
	borderSprite2.setTextureRect(sf::IntRect(0, 0, 100, 100));
	characterSprite2.setTexture(character);
	characterSprite2.setTextureRect(sf::IntRect(100, 0, 100, 100));
	borderSprite3.setTexture(character);
	borderSprite3.setTextureRect(sf::IntRect(0, 0, 100, 100));
	characterSprite3.setTexture(character);
	characterSprite3.setTextureRect(sf::IntRect(100, 0, 100, 100));
	borderSprite4.setTexture(character);
	borderSprite4.setTextureRect(sf::IntRect(0, 0, 100, 100));
	characterSprite4.setTexture(character);
	characterSprite4.setTextureRect(sf::IntRect(100, 0,100, 100));

	controlsSprite1.setTexture(character);
	controlsSprite1.setTextureRect(sf::IntRect(250, 0, 100, 100));
	controlsSprite2.setTexture(character);
	controlsSprite2.setTextureRect(sf::IntRect(350, 0, 100, 100));
	controlsSprite3.setTexture(character);
	controlsSprite3.setTextureRect(sf::IntRect(0, 100, 100, 100));
	controlsSprite4.setTexture(character);
	controlsSprite4.setTextureRect(sf::IntRect(150, 100, 100, 100));
	k = 0;
	borderSprite1.setPosition(400, 200);
	borderSprite1.scale(3, 3);
	characterSprite1.setPosition(200, 90);
	
	characterSprite1.scale(5,5);
	borderSprite2.setPosition(800, 200);
	borderSprite2.scale(3, 3);
	characterSprite2.setPosition(600, 90);
	characterSprite2.scale(5, 5);
	characterSprite2.setColor(sf::Color(255, 0, 0));
	borderSprite3.setPosition(400, 400);
	borderSprite3.scale(3, 3);
	characterSprite3.setPosition(200, 290);
	characterSprite3.scale(5, 5);
	characterSprite3.setColor(sf::Color(0, 0, 255));
	borderSprite4.setPosition(800, 400);
	borderSprite4.scale(3, 3);
	characterSprite4.setPosition(600, 290);
	characterSprite4.scale(5, 5);
	characterSprite4.setColor(sf::Color(0, 255, 0));

	titleBackgroundSprite.setTexture(titleBackground);
	titleBackgroundSprite.scale(2, 2);
	titleBackgroundSprite.setPosition(position1.x, position1.y);

	titleLogoSprite.setTexture(titleLogo);
	titleLogoSprite.scale(14, 14);
	titleLogoSprite.setPosition(position2.x, position2.y);

	selectionSprite.setTexture(selection);
	selectionSprite.scale(1.3, 1.3);
	selectionSprite.setPosition(position3);

	singleLogoSprite.setTexture(singleLogo);
	singleLogoSprite.scale(1.3, 1.3);
	singleLogoSprite.setPosition(position4);

	multiLogoSprite.setTexture(multiLogo);
	multiLogoSprite.scale(1.3, 1.3);
	multiLogoSprite.setPosition(position5);

	i = 0;
	atStart = true;
}

void inTitle::titleLogic(){
	
	inTitle::window1->clear(sf::Color(255, 255, 255, 40));
	inTitle::window1->draw(titleBackgroundSprite);

	if (atStart) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window1->close();
		}

		if (events->type == sf::Event::KeyPressed)
		{

			if (events->key.code == sf::Keyboard::Up && !pressed)
			{
				i = i + 1;
			}

			if (events->key.code == sf::Keyboard::Down && !pressed)
			{
				i = i - 1;
			}

			pressed = true;
		}

		else if (events->type == sf::Event::KeyReleased)
		{
			pressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (i == 0) {
				clock.restart();
				single = true;
				multi = false;
				atStart = false;

			}
			if (i == 1) {
				clock.restart();
				single = false;
				multi = true;
				atStart = false;
			}
		}
	}
	
	

	controlsSprite1.setPosition(1070, 300);
	
	controlsSprite2.setPosition(360, 520);
	
	if (!player4) {
		controlsSprite3.setPosition(1060, 500);
	}
	
	

	if (single) {
		transition();
	}
	else if (multi) {
		transition();
	}
	else if (characterselectsingle) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player2 = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			player3 = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home)) {
			player4 = true;
		}

		single = false;
		multi = false;
		inTitle::window1->draw(borderSprite1);
		inTitle::window1->draw(borderSprite2);
		inTitle::window1->draw(borderSprite3);
		inTitle::window1->draw(borderSprite4);

		inTitle::window1->draw(controlsSprite1);
		inTitle::window1->draw(controlsSprite2);
		inTitle::window1->draw(controlsSprite3);
	    
		if (player1){ inTitle::window1->draw(characterSprite1); }
		if (player2){
			controlsSprite1.setPosition(1060, 300);
			inTitle::window1->draw(characterSprite2);  
		controlsSprite1.setTextureRect(sf::IntRect(100, 100, 150, 150));
		
		}
		if (player3){ inTitle::window1->draw(characterSprite3);  
		controlsSprite2.setTextureRect(sf::IntRect(240, 100, 120, 150));
		}
		if (player4){
			controlsSprite3.setPosition(1090, 500);
			inTitle::window1->draw(characterSprite4); 
		controlsSprite3.setTextureRect(sf::IntRect(350, 100, 150, 150));
		
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{ 
			state = 1;
			if (player1) { k += 1; }
			if (player2) { k += 1; }
			if (player3) { k += 1; }
			if (player4) { k += 1; }
			std::cout << k;
			characterselectsingle = false;
			return;
		}

	}
	

	if (i == 1 && !single && !multi && !characterselectsingle) {position3 = sf::Vector2f(651, 702);}
	if (i == 0 && !single && !multi && !characterselectsingle) {position3 = sf::Vector2f(651, 602);}

	if (i < 0) {
		i = 1;
	}
	if (i > 1) {
		i = 0;
	}

	multiLogoSprite.setPosition(position5);
	singleLogoSprite.setPosition(position4);
	selectionSprite.setPosition(position3);
	titleLogoSprite.setPosition(position2.x, position2.y);

	inTitle::window1->draw(selectionSprite);
	inTitle::window1->draw(titleLogoSprite);
	inTitle::window1->draw(singleLogoSprite);
	inTitle::window1->draw(multiLogoSprite);
	inTitle::window1->display();
	
}

void inTitle::transition() {
	if (clock.getElapsedTime().asSeconds() < 1.5) {
		position2.x -= 1.5 * clock.getElapsedTime().asSeconds();
		position3.x -= 1.5 * clock.getElapsedTime().asSeconds();
		position4.x -= 1.5 * clock.getElapsedTime().asSeconds();
		position5.x -= 1.5 * clock.getElapsedTime().asSeconds();
	}
	else {
		single = false;
		multi = false;
		characterselectsingle = true;
	}
	
}
