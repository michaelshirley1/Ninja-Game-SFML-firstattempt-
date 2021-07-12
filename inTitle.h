#pragma once
#include "sfml.h"
#include "baseGameStates.h"
#include "playerMod.h"
#include "collision.h"
#include "maps.h"

class inTitle {
public:sf::RenderWindow* window1;
public:gameStates* gameState;
	  sf::Event* events;
	  sf::Texture titleLogo;
	  sf::Sprite titleLogoSprite;
	  bool pressed;
	  int i;
	  int k;
	  int state;
	  int * play;
	  sf::Clock clock;
	  bool single;
	  bool multi;
	  bool atStart;
	  bool characterselectsingle;
	  sf::Vector2f position1 = sf::Vector2f(-100.0f, -500.0f);
	  sf::Vector2f position2 = sf::Vector2f(300.0f, -100);
	  sf::Vector2f position3 = sf::Vector2f(650, 600);
	  sf::Vector2f position4 = sf::Vector2f(650, 600);
	  sf::Vector2f position5 = sf::Vector2f(650, 700);
	  sf::Texture singleLogo;
	  sf::Sprite singleLogoSprite;
	  sf::Texture selection;
	  sf::Sprite selectionSprite;
	  sf::Texture titleBackground;
	  sf::Sprite titleBackgroundSprite;
	  sf::Texture multiLogo;
	  sf::Sprite multiLogoSprite;
	  bool player1;
	  bool player2;
	  bool player3;
	  bool player4;
	  sf::Texture border;
	  sf::Texture character;
	  sf::Sprite borderSprite1;
	  sf::Sprite controlsSprite1;
	  sf::Sprite characterSprite1;
	  sf::Sprite borderSprite2;
	  sf::Sprite controlsSprite2;
	  sf::Sprite characterSprite2;
	  sf::Sprite borderSprite3;
	  sf::Sprite controlsSprite3;
	  sf::Sprite characterSprite3;
	  sf::Sprite borderSprite4;
	  sf::Sprite controlsSprite4;
	  sf::Sprite characterSprite4;
	

public:inTitle(sf::RenderWindow* window, int * x, int * y, sf::Event* event1);
	  void titleLogic();
	  void transition();
	  void characterSelect();
};