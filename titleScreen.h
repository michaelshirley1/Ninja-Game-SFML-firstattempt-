#pragma once
#include "sfml.h"
#include "baseGameStates.h"

class titleScObj {
public:sf::RenderWindow * window1;
public:gameStates * gameState;
	public:titleScObj(sf::RenderWindow* window, gameStates* state);
	public:void drawTitle();
	public:void titleLogic();
};