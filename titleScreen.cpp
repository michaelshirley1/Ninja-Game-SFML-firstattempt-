#include "titleScreen.h"
#include "inGame.h"
#include "baseGameStates.h"
#include <iostream>
#include "sfml.h"
sf::Sprite sprite;
sf::Text titletext;


titleScObj::titleScObj(sf::RenderWindow* window, gameStates* state) {
	
	window1 = window;
	gameState = state;
	sf::Texture texture;
	texture.loadFromFile("test.png");
	// Create a sprite
	

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(100, 100, 50, 30));
	sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(100, 25);
	titletext.setPosition(300, 200);
	titletext.setScale(100, 100);
	titletext.setFillColor(sf::Color(255, 255, 255, 200));
	titletext.setString("Ninja Game");
	
}

void titleScObj::titleLogic() {
	if (*gameState == titleScreen) {
		drawTitle();
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		*gameState = inGame;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window1->close();
	}
}

void titleScObj::drawTitle() {
	
	titleScObj::window1->clear(sf::Color(255, 255, 0, 0));
	titleScObj::window1->draw(sprite);
	titleScObj::window1->draw(titletext);
	
	
	
}