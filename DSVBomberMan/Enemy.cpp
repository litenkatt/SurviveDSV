#include "Enemy.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

using namespace engine;

namespace survivedsv {
	Enemy::Enemy(int x, int y, int w, int h) : MovingSprite(x, y, w, h)
	{
		SDL_Surface* surf = IMG_Load("enemy.png");
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);

	}
	Enemy * Enemy::getInstance()
	{
		return new Enemy(500, 100, 100, 100);
	}
	Enemy::~Enemy()
	{
		SDL_DestroyTexture(texture);
	}
	void Enemy::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}
}

