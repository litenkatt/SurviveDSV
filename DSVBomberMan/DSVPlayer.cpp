#include "DSVPlayer.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

using namespace engine;

namespace survivedsv {
	DSVPlayer::DSVPlayer(int x, int y, int w, int h, int pic) : Player(x, y, w, h)
	{
		SDL_Surface* surf;
		if(pic == 1)
		surf = IMG_Load("marcus.png");
		else if(pic == 2)
		surf = IMG_Load("ninni.png");
		else
		surf = IMG_Load("tove.png");
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);

	}
	DSVPlayer * DSVPlayer::getInstance(int pic)
	{
		return new DSVPlayer(300, 100, 100, 100, pic);
	}
	DSVPlayer::~DSVPlayer()
	{
		SDL_DestroyTexture(texture);
	}
	void DSVPlayer::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}

}