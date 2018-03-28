#include "Obstacle.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace engine;

	Obstacle * Obstacle::getInstance(int lev, int x, int y)
	{
		return new Obstacle(x, y, lev);
	}
	Obstacle::~Obstacle()
	{
		SDL_DestroyTexture(green);
		SDL_DestroyTexture(yellow);
		SDL_DestroyTexture(red);
	}
	Obstacle::Obstacle(int x, int y, int lev) : StillSprite(x, y), level(lev)
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


