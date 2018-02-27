#include "Obstacle.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace engine;

namespace survivedsv {
	Obstacle * Obstacle::getInstance(int lev)
	{
		
		return new Obstacle(100, 200, 100, 100, lev);
	}
	Obstacle::~Obstacle()
	{
		SDL_DestroyTexture(green);
		SDL_DestroyTexture(yellow);
		SDL_DestroyTexture(red);
	}
	Obstacle::Obstacle(int x, int y, int w, int h, int lev) : StillSprite(x, y, w, h), level(lev)
	{

		green = IMG_LoadTexture(eng.getRen(), "greentile.png");
		yellow = IMG_LoadTexture(eng.getRen(), "yellowtile.png");
		red = IMG_LoadTexture(eng.getRen(), "redtile.png");
	}
	void Obstacle::draw() const
	{
		if (level == 1)
			SDL_RenderCopy(eng.getRen(), green, NULL, &getRect());
		else if(level == 2)
			SDL_RenderCopy(eng.getRen(), yellow, NULL, &getRect());
		else
			SDL_RenderCopy(eng.getRen(), red, NULL, &getRect());
	}
}

