
#pragma once
#include "sfml.h"
#include "baseGameStates.h"
#include "playerMod.h"
#include "collision.h"
#include "maps.h"
#include "animation.h"

class gameScObj {
public:sf::RenderWindow* window1;
public:gameStates* gameState;
	  int playerCount;
	  sf::Event* eventz;

	physicObject::player* main[4];
	physicObject::player* main1;
	physicObject::player* main2;
	physicObject::player* main3;
	physicObject::player* main4;

	   sf::Texture backgroundImage;
	   sf::Sprite backgroundSprite;

	   sf::Sprite player1SpriteBack;
	   sf::Sprite player2SpriteBack;
	   sf::Sprite player3SpriteBack;
	   sf::Sprite player4SpriteBack;

	   sf::Text player1HeathText;
	   sf::Text player2HeathText;
	   sf::Text player3HeathText;
	   sf::Text player4HeathText;

	   maps::testmap* map;

	   bool player1;
	   bool player2;
	   bool player3;
	   bool player4;

	   int shaking;

	   Animation* death;
	   sf::Sprite explosion;
	   sf::View view1;
	   bool shake;
	   sf::Clock timer;

public:gameScObj(sf::RenderWindow* window, int * x, int * y, sf::Event* event1);
public:void drawGameObj();
public:void gameLogic();
	   void loadTextures();
	   void collisionDetection();
	   void universalPhysics();
	   void arrangePhysicsObjects();
};