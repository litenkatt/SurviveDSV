#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "GameEngine.h"
#include <typeinfo>
#include <iostream>
#include <vector>

namespace engine {
	Player::Player(int x, int y, int speed, int superTime) 
		: MovingSprite(x, y, eng.getTileSize(), eng.getTileSize(), speed), superMode(false), superTime(superTime)
	{
	}
	Player::~Player()
	{
	}
	void Player::collision(int x, Sprite* s) {
		Enemy *e;
		PowerUp *p;
		if (e = dynamic_cast<Enemy *>(s)) {
			if (superMode) {
				eng.nextLevel();
			}
			else {
				eng.gameOver();
			}	
		}else if (p = dynamic_cast<PowerUp *>(s)) {
			std::cout << x;
			eng.deleteSprite(x);
			superMode = true;
			resetSteps(superTime);

		}//if
	}//collision
}

