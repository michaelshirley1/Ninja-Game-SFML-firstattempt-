#pragma once
#include "sfml.h"
#include "playerMod.h"

class characterSelectSingle {
public:
public:sf::RenderWindow* window1;
	  int playerCount;
	  sf::Event* eventz;
	  physicObject::player* main[4];
	  physicObject::player* main1;
	  physicObject::player* main2;
	  sf::Texture backgroundImage;
	  sf::Sprite backgroundSprite;
public:characterSelectSingle(sf::RenderWindow* window, int* x, sf::Event* event1);
public:void drawSelectObj();
public:void selectLogic();
	  void loadTextures();
	  void collisionDetection();
	  void universalPhysics();
	  void arrangePhysicsObjects();
};