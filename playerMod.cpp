#include "playerMod.h"
#include <iostream>
#include "animation.h"

physicObject::player::player(sf::RenderWindow* window, int spawnPosX, int spawnPosY, int playerNo, sf::Event* event1) {
	damage = 0;
	eventz = event1;
	PlayNo = playerNo;
	inVun = false;
	lives = 5;
	clock.restart();
	clock2.restart();
	this->position.x = spawnPosX;
	this->position.y = spawnPosY;
	this->dirspeedX = 0;
	this->dirspeedY = 0;
	this->window1 = window;
	this->width = 50;
	this->height = 50;
	this->sprite2.setScale(0.1, 0.1);
	this->grounded = false;
	this->sprite2.setPosition(position.x, position.y);
	this->rectangle = *new sf::Rect<float>((position.x, position.y), (position.x +10, position.y), width, height);
	dead = false;

	if (PlayNo == 1) {
		idlesprite.setColor(sf::Color(255, 0, 0));
		idlesprite2.setColor(sf::Color(255, 0, 0));
		blockingSprite.setColor(sf::Color(255, 0, 0));
		run1sprite.setColor(sf::Color(255, 0, 0));
		run2sprite.setColor(sf::Color(255, 0, 0));
		slashsprite.setColor(sf::Color(255, 0, 0));
		slashsprite2.setColor(sf::Color(255, 0, 0));
	}
	if (PlayNo == 2) {
		sprite2.setColor(sf::Color(0, 0 , 255));
		idlesprite.setColor(sf::Color(0, 0, 255));
		idlesprite2.setColor(sf::Color(0, 0, 255));
		blockingSprite.setColor(sf::Color(0, 0, 255));
		run1sprite.setColor(sf::Color(0, 0, 255));
		run2sprite.setColor(sf::Color(0, 0, 255));
		slashsprite.setColor(sf::Color(0, 0, 255));
		slashsprite2.setColor(sf::Color(0, 0, 255));
	}
	if (PlayNo == 3) {
		sprite2.setColor(sf::Color(0, 255, 0));
		idlesprite.setColor(sf::Color(0, 255, 0));
		idlesprite2.setColor(sf::Color(0, 255, 0));
		blockingSprite.setColor(sf::Color(0, 255, 0));
		run1sprite.setColor(sf::Color(0, 255, 0));
		run2sprite.setColor(sf::Color(0, 255, 0));
		slashsprite.setColor(sf::Color(0, 255, 0));
		slashsprite2.setColor(sf::Color(0, 255, 0));
	}

	blocking1.loadFromFile("blocking96.png");
	run1.loadFromFile("run.png");
	run2.loadFromFile("run.png");
	idle.loadFromFile("idle.png");
	slash.loadFromFile("slash.png");
	gotHit1.loadFromFile("take_hit.png");
	blockingSprite.setTexture(blocking1);
	blockingSprite.setScale(0.4, 0.4);
	run1sprite.setScale(0.8, 0.8);
	run1sprite.setTexture(run1);
	run2sprite.setTexture(run2);
	run2sprite.scale(-0.8, 0.8);
	idlesprite.setTexture(idle);
	idlesprite.setScale(0.8, 0.8);
	idlesprite2.setTexture(idle);
	idlesprite2.setScale(-0.8, 0.8);
	slashsprite.setTexture(slash);
	slashsprite.setScale(0.8, 0.8);
	slashsprite2.setTexture(slash);
	slashsprite2.setScale(-0.8, 0.8);
	gotHit1sprite.setTexture(gotHit1);
	gotHit1sprite.setScale(0.8, 0.8);
	gotHit1sprite2.setTexture(gotHit1);
	gotHit1sprite2.setScale(-0.8, 0.8);
	on = false;
	runningRightA = new Animation(&run1sprite, 6, &clock);
	runningLeftA = new Animation(&run2sprite, 6, &clock);
	attackingA2 = new Animation(&slashsprite, 6, &clock);
	attackingA = new Animation(&slashsprite2, 6, &clock);
	gotHitA = new Animation(&gotHit1sprite, 5, &clock);
	gotHitA2 = new Animation(&gotHit1sprite2, 5, &clock);
	idlingA = new Animation(&idlesprite, 7, &clock);
	idlingA1 = new Animation(&idlesprite2, 7, &clock);
	blockingA = new Animation(&blockingSprite, 27, &clock);

	runningRightA->addFrame( sf::IntRect(0,0,32,32), 0.2 );
	runningRightA->addFrame( sf::IntRect(32,0,32,32), 0.2 );
	runningRightA->addFrame( sf::IntRect(64,0,32,32), 0.2 );
	runningRightA->addFrame( sf::IntRect(96,0,32,32), 0.2 );
	runningRightA->addFrame( sf::IntRect(128,0,32,32), 0.2 );
	runningRightA->addFrame( sf::IntRect(160,0,32,32), 0.1 );

	runningLeftA->addFrame(sf::IntRect(0,0,32,32), 0.4 );
	runningLeftA->addFrame( sf::IntRect(32,0,32,32), 0.4 );
	runningLeftA->addFrame( sf::IntRect(64,0,32, 32), 0.4 );
	runningLeftA->addFrame( sf::IntRect(96,0,32,32), 0.4 );
	runningLeftA->addFrame( sf::IntRect(128,0,32,32), 0.4 );
	runningLeftA->addFrame( sf::IntRect(160,0,32,32), 0.1 );

	attackingA->addFrame( sf::IntRect(0,0,32,32), 0.2 );
	attackingA->addFrame( sf::IntRect(32,0,32,32), 0.2 );
	attackingA->addFrame( sf::IntRect(64,0,32,32), 0.2 );
	attackingA->addFrame( sf::IntRect(96,0,32,32), 0.2 );
	attackingA->addFrame( sf::IntRect(128,0,32,32), 0.2 );
	attackingA->addFrame(sf::IntRect(160,0,32,32), 0.01);

	attackingA2->addFrame(sf::IntRect(0, 0, 32, 32), 0.1);
	attackingA2->addFrame(sf::IntRect(32, 0, 32, 32), 0.1);
	attackingA2->addFrame(sf::IntRect(64, 0, 32, 32), 0.1);
	attackingA2->addFrame(sf::IntRect(96, 0, 32, 32), 0.1);
	attackingA2->addFrame(sf::IntRect(128, 0, 32, 32), 0.2);
	attackingA2->addFrame(sf::IntRect(160, 0, 32, 32), 0.01);

	gotHitA->addFrame( sf::IntRect(0,0,32,32), 0.1);
	gotHitA->addFrame( sf::IntRect(32,0,32,32), 0.1 );
	gotHitA->addFrame( sf::IntRect(64,0,32,32), 0.1 );
	gotHitA->addFrame( sf::IntRect(96,0,32,32), 0.1 );
	gotHitA->addFrame( sf::IntRect(128,0,32,32), 0.1 );

	gotHitA2->addFrame(sf::IntRect(0, 0, 32, 32), 0.1);
	gotHitA2->addFrame(sf::IntRect(32, 0, 32, 32), 0.1);
	gotHitA2->addFrame(sf::IntRect(64, 0, 32, 32), 0.1);
	gotHitA2->addFrame(sf::IntRect(96, 0, 32, 32), 0.1);
	gotHitA2->addFrame(sf::IntRect(128, 0, 32, 32), 0.1);

	idlingA->addFrame(sf::IntRect(0,0,32,32), 1 );
	idlingA->addFrame(sf::IntRect(32,0,32,32), 1);
	idlingA->addFrame(sf::IntRect(64,0,32,32), 1 );
	idlingA->addFrame(sf::IntRect(96,0,32,32), 1 );
	idlingA->addFrame(sf::IntRect(128, 0, 32, 32),1);
	idlingA->addFrame(sf::IntRect(160, 0, 32, 32),0.2);
	idlingA->addFrame(sf::IntRect(192, 0, 32, 32), 0.2);

	idlingA1->addFrame(sf::IntRect(0, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(32, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(64, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(96, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(128, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(160, 0, 32, 32), 1);
	idlingA1->addFrame(sf::IntRect(192, 0, 32, 32), 1);

	blockingA->addFrame(sf::IntRect(0, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(96, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(192, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(288, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(384, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(480, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(576, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(672, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(768, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(864, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(960, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1056, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1152, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1248, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1344, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1440, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1536, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1632, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1728, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1824, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(1920, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2016, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2112, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2208, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2304, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2400, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2496, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2592, 0, 96, 96), 0.1);
	blockingA->addFrame(sf::IntRect(2688, 0, 96, 96), 0.01);

	idlingb = true;
	runningRight = true;
	idlesprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite2 = idlesprite;
	
	
	
}

bool physicObject::player::getInput(int playerNo, int control) {
	switch (playerNo) {
	case 0:
		switch (control) {
		case 0:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
		case 1:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
		case 2:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));
		case 3:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right));
		case 4:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N));
		case 5:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M));
		}

	case 1:
		switch (control) {
		case 0:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
		case 1:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S));
		case 2:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
		case 3:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D));
		case 4:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V));
		case 5:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B));
		}
	case 2:
		switch (control) {
		case 0:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I));
		case 1:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K));
		case 2:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J));
		case 3:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L));
		case 4:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::SemiColon));
		case 5:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Quote));
		}
	case 3:
		switch (control) {
		case 0:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Home));
		case 1:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::End));
		case 2:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Delete));
		case 3:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::PageDown));
		case 4:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period));
		case 5:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma));
		}

	}

	return false;
}

void physicObject::player::updateMovement(sf::RenderWindow * window) {

	dirspeedY = dirspeedY + gravity;
	position.y = position.y + dirspeedY;
	position.x = position.x + dirspeedX;


		if (getInput(PlayNo, 3)) {
			clockAttack.restart();
			runningRight = true;
			sprite2 = run1sprite;
			if (dirspeedX < 0.55) {
				dirspeedX += 0.00012;
			}
			runningRightb = true;
			gotHitb = false;
			attackingb = false;
			runningLeftb = false;
			idlingb = false;
			jumpingb = false;
			
			
		}
		else {
			if (dirspeedX >= 0) {
				dirspeedX -= 0.0002;
			}

		}

		if (getInput(PlayNo, 2)) {
			clockAttack.restart();
			runningRight = false;
			sprite2 = run2sprite;
			if (dirspeedX > -0.55) {
				dirspeedX -= 0.00012;
			}
			runningRightb = false;
			gotHitb = false;
			attackingb = false;
			runningLeftb = true;
			idlingb = false;
			jumpingb = false;
			
			

		}
		else {
			if (dirspeedX <= 0) {
				dirspeedX += 0.0002;
			}
		}


		if (getInput(PlayNo, 0) && grounded) {
			clockAttack.restart();
			dirspeedY -= 0.55;
			grounded = false;
			runningRightb = false;
			gotHitb = false;
			attackingb = false;
			runningLeftb = false;
			idlingb = false;
			jumpingb = true;

		}
		else {
			if (dirspeedY >= 0) {
				dirspeedY -= 0.0002;
			}
			if (dirspeedY <= 0) {
				dirspeedY += 0.0002;
			}
		}

		if (getInput(PlayNo, 4) && !blocking) {
			clockAttack.restart();
			runningRightb = false;
			gotHitb = false;
			attackingb = true;
			runningLeftb = false;
			idlingb = false;
			jumpingb = false;

			if (runningRight) {
				sprite2 = slashsprite;
			}
			else {
				sprite2 = slashsprite2;
			}
		}
		
		
		if (!getInput(PlayNo, 3) && !getInput(PlayNo, 0) && !getInput(PlayNo, 4) && !getInput(PlayNo, 2)) {
			runningRightb = false;
			gotHitb = false;
			attackingb = false;
			runningLeftb = false;

			if (runningRight) {
				blockingSprite.setPosition(position.x - 8, position.y - 5);
			}
			else {
				blockingSprite.setPosition(position.x - 35, position.y - 5);
			}
			if (clockAttack.getElapsedTime().asSeconds() > 0.2) {
				idlingb = true;
				if (runningRight) {
					sprite2 = idlesprite;
				}
				else{
					sprite2 = idlesprite2;
				}
			}
			
		}

		if (getInput(PlayNo, 5) && !attackingb) {
			clock.restart();
			blocking = true;
		}
		else {
			blocking = false;
		}


		if (idlingb) {
			if (runningRight) {
				idlingA->update(clock.getElapsedTime().asSeconds());
				blockingSprite.setPosition(position.x - 8, position.y - 5);
			}
			else {
				idlingA1->update(clock.getElapsedTime().asSeconds());
				blockingSprite.setPosition(position.x - 35, position.y - 5);
			}
		}
		else if (runningRightb) {
			runningRightA->update(clock.getElapsedTime().asSeconds());
			blockingSprite.setPosition(position.x - 8, position.y - 5);
		}
		else if (runningLeftb) {
			runningLeftA->update(clock.getElapsedTime().asSeconds());
			blockingSprite.setPosition(position.x - 35, position.y - 5);
		}
		else if (attackingb) {
			attackingA->update(clock.getElapsedTime().asSeconds());  attackingA2->update(clock.getElapsedTime().asSeconds());
		}
		if (blocking) {
			blockingA->update(clock.getElapsedTime().asSeconds());
		}

		if (prevposition.x == 0.0000 && prevposition.y == 0.0000) {
			prevposition = position;
		}


	sprite2.setPosition(position.x, position.y);
	rectangle.left = (position.x, position.y);
}

sf::Sprite physicObject::player::getSprite(){
	return sprite2;
}

void physicObject::player::gotHit(physicObject::player * prop) {
	if (clock2.getElapsedTime().asSeconds() > 0.5) {
		clock2.restart();
		damage += 0.075;
		int relationx = prop->position.x - position.x;
		int relationy = prop->position.y - position.y;

		if (relationx > 0) {
			dirspeedX -= damage;
		}
		if (relationx < 0) {
			dirspeedX += damage;
		}
		if (relationy > 0) {
			dirspeedY -= damage;
		}
		if (relationy < 0) {
			dirspeedY += damage;
		}
	}
}

void physicObject::player::gotBlocked(physicObject::player* prop) {
	int relationx = prop->position.x - position.x;
	int relationy = prop->position.y - position.y;

	if (relationx > 0) {
		damage += 0.00000025;
		dirspeedX -= 0.00075;
	}
	if (relationx < 0) {
		damage += 0.00000025;
		dirspeedX += 0.00075;
	}
	if (relationy > 0) {
		damage += 0.00000025;
		dirspeedY -= 0.00075;
	}
	if (relationy < 0) {
		damage += 0.00000025;
		dirspeedY += 0.00075;
	}
}

void physicObject::player::setPosX(float x, float y) {
	this->position.x = x;
	this->position.y = y;
}

void physicObject::player::died() {
	if (clock.getElapsedTime().asSeconds() < 1.5) {
		std::cout << clock.getElapsedTime().asSeconds() << std::endl;

	}
	else {
		lives = lives - 1;
		std::cout << lives << std::endl;
		sf::Vector2f reset(200.0, 10.0);
		position = reset;
		clock.restart();
	}
	
	
	
}
