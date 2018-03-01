#include "GameLoop.h"
#include <SDL.h>
#include <iostream>
#include "GameEngine.h"

namespace engine {
	void GameLoop::add(Sprite* s) {
		comps.push_back(s);
	}
	void GameLoop::addPlayer(Player* player) {
		p = player;
		comps.push_back(player);
	}

	void GameLoop::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				//std::cout << "här är inre whilen";
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					std::cout << "such press";
					break;
				case SDL_KEYDOWN:
					switch (eve.key.keysym.sym) {
						case SDLK_RIGHT: p->right();
							break;
						case SDLK_LEFT: p->left();
							break;
						case SDLK_UP: p->up();
							break;
						case SDLK_DOWN: p->down();
							break;
					}

					break;
				} // switch
			} // inre while
			SDL_SetRenderDrawColor(eng.getRen(), 255, 0, 0, 255);
			SDL_RenderClear(eng.getRen());
			for (Sprite* s : comps) {
				s->draw();
			}//for
				
			SDL_RenderPresent(eng.getRen());

		} //yttre while

	}

	GameLoop::~GameLoop()
	{
	}
}



