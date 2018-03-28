#include "DSVPlayer.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"
#include "Label.h"
#include <iostream>

using namespace engine;

	DSVPlayer::DSVPlayer(int x, int y, int pic, int speed, 
		int superTime) : Player(x, y, speed, superTime)
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
		SDL_Surface* superSurf = IMG_Load("inlamning.png");
		assText = SDL_CreateTextureFromSurface(eng.getRen(), superSurf);
		SDL_FreeSurface(superSurf);
	}
	DSVPlayer * DSVPlayer::getInstance(int pic, int x, int y, 
		int speed, int superTime)
	{
		return new DSVPlayer(x, y, pic, speed, superTime);
	}
	DSVPlayer::~DSVPlayer()
	{
		SDL_DestroyTexture(texture);
	}

	void DSVPlayer::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
		if (getMode()) {
			SDL_Rect assRect = { getX() + (getW() / 2), getY() + 
				(getH() / 2), getW() / 2, getH() / 2 };
			SDL_RenderCopy(eng.getRen(), assText, NULL, &assRect);
		}
	}



