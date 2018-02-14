#include "GameEngine.h"
#include <SDL.h>

namespace engine {
	GameEngine::GameEngine()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("SurviveDSV", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 600, 400, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 36);
	}


	GameEngine::~GameEngine()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Renderer* GameEngine::getRen() const {
		return ren;
	}

	TTF_Font* GameEngine::getFont() const {
		return font;
	}
	GameEngine eng;
}

