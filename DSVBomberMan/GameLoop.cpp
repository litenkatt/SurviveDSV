#include "GameLoop.h"
#include <SDL.h>
#include <iostream>
#include "GameEngine.h"

namespace engine {
	void GameLoop::add(Sprite* s) {
		comps.push_back(s);
	}

	void GameLoop::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				std::cout << "här är inre whilen";
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					std::cout << "such press";
					break;

				} // switch
			} // inre while
			SDL_SetRenderDrawColor(eng.getRen(), 255, 0, 0, 255);
			SDL_RenderClear(eng.getRen());
			for (Sprite* s : comps) {
				s->draw();
				std::cout << comps.size();
			}//for
				
			SDL_RenderPresent(eng.getRen());

		} //yttre while

	}

	GameLoop::~GameLoop()
	{
	}
}



