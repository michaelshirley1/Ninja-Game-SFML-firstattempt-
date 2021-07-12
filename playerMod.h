#pragma once
#include "sfml.h"
#include "animation.h"
class physicObject {
public:
	class player {
	public:
		sf::Event * eventz;
		sf::RenderWindow* window1;
		   player(sf::RenderWindow* window, int spawnPosX, int spawnPosY, int playerNo, sf::Event * event1);
		   sf::Clock clock;
		   sf::Clock clock2;
		   sf::Clock clockAttack;
		   int PlayNo;
		   bool on;
		   bool inVun;
		   int lives;
		   float damage;
		   sf::Vector2f position;
		   sf::Vector2f prevposition;
		   sf::Sprite sprite2;
		   sf::Texture run1;
		   sf::Texture run2;
		   sf::Texture idle;
		   sf::Texture slash;
		   sf::Texture gotHit1;
		   sf::Texture blocking1;
		   sf::Sprite blockingSprite;
		   sf::Sprite run1sprite;
		   sf::Sprite run2sprite;
		   sf::Sprite idlesprite;
		   sf::Sprite idlesprite2;
		   sf::Sprite slashsprite;
		   sf::Sprite slashsprite2;
		   sf::Sprite slashspriteQ;
		   sf::Sprite gotHit1sprite;
		   sf::Sprite gotHit1sprite2;
		   bool gotHitb;
		   bool attackingb;
		   bool runningLeftb;
		   bool runningRightb;
		   bool idlingb;
		   bool jumpingb;
		   bool runningRight;
		   bool blocking;
		   bool dead;
		   Animation* runningRightA;
		   Animation* runningLeftA;
		   Animation* attackingA;
		   Animation* attackingA2;
		   Animation* gotHitA;
		   Animation* gotHitA2;
		   Animation* idlingA;
		   Animation* idlingA1;
		   Animation* blockingA;

		  

		   sf::Rect<float> rectangle;
		   float dirspeedX, width, dirspeedY, height;
		   float gravity = 0.00051;
		   bool grounded;
		   void updateMovement(sf::RenderWindow* window);
		   sf::Sprite getSprite();
		   void gotHit(physicObject::player* prop);
		   void gotBlocked(physicObject::player* prop);
		   bool getInput(int playerNo, int control);
		   void setPosX(float x, float y);
		   void died();

	};
};
