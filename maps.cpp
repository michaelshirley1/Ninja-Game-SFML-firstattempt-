#include "maps.h"
#include "collision.h"

maps::testmap::testmap() {
	objects[0] = new collisionObjectSquare(100, 500, 430, 410, 0, true, 3, 1.5);
	objects[1] = new collisionObjectSquare(300, 300, 350, 0, 0, true, 1, 1);
	objects[2] = new collisionObjectSquare(600, 300, 1000, 0, 0, true, 1, 1);
	objects[3] = new collisionObjectSquare(900, 500, 1500, 0, 0, true, 3, 1.5);
}
void maps::testmap::setupObjects() {
	
}