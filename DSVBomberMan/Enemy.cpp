#include "Enemy.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

using namespace engine;

namespace engine {
	Enemy::Enemy(int x, int y, int speed) 
		: MovingSprite(x, y, eng.getTileSize(), eng.getTileSize(), speed)
	{
	}
	Enemy::~Enemy()
	{
	}
	void Enemy::collision(int x, Sprite* s) {
		Player *p;
		if (p = dynamic_cast<Player *>(s)) {
			if (p->getMode()) {
				eng.nextLevel();
			}
			else {
				eng.gameOver();
			}
		}
	}//collision
}

