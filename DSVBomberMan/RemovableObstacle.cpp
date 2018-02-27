#include "RemovableObstacle.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

using namespace engine;

namespace survivedsv {
	RemovableObstacle * RemovableObstacle::getInstance()
	{
		return new RemovableObstacle(100, 100, 100, 100);
	}

	RemovableObstacle::RemovableObstacle(int x, int y, int w, int h) : StillSprite(x, y, w, h)
	{
		SDL_Surface* surf = IMG_Load("brickwall.png");
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	RemovableObstacle::~RemovableObstacle()
	{
		SDL_DestroyTexture(texture);
		
	}

	void RemovableObstacle::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}
}


