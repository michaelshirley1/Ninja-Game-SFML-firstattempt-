#include "sfml.h"
#include "playerMod.h"
#include "collision.h"

collisionObjectSquare::collisionObjectSquare(int x11, int y11, int x22, int y22, float mass1, bool fixed1, float scale, float scale2) {
	this->x = x11;
	this->y = y11;
	this->x1 = x22;
	this->y1 = y22;
	this->x2 = x22;
	this->y2 = y11;
	this->x3 = x11;
	this->y3 = y22;
	this->mass = mass1;
	this->fixed = fixed1;
	this->width = fabs(x - x1);
	this->height = fabs(y - y1);
	this->texture.loadFromFile("platform1.png");
	this->sprite.setTexture(texture);
	this->sprite.setScale(scale, scale2);
	this->sprite.setPosition(x, y);
	this->rectangle = *new sf::Rect<float>((x,y),(x + 10,y + 10), width, height);
}

void collisionObjectSquare::updateCollisions() {
	sprite.setPosition(x, y);
}