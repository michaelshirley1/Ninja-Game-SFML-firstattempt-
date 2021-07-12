#pragma once
#include "sfml.h"
#include "playerMod.h"


class collisionObjectSquare {
public:
	float x, y, x1, y1, x2, y2, x3, y3, width, height;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Rect<float> rectangle;
	bool fixed;
	float mass;
	float vx, vy;
public:collisionObjectSquare(int x1, int y1, int x2, int y2, float mass, bool fixed, float scale, float scale2);
public:void updateCollisions();
};
