#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <algorithm>


namespace engine {
	GameEngine::GameEngine()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("SurviveDSV", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, winW, winH, 0);
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

	int GameEngine::getCharacter() const
	{
		return c;
	}

	int GameEngine::getTileSize() const
	{
		return tileSize;
	}

	int GameEngine::getWinW() const {
		return winW;
	}
	int GameEngine::getWinH() const {
		return winH;
	}

	std::vector<Sprite*> GameEngine::getSprites() const
	{
		return comps;
	}

	void GameEngine::deleteSprite(int x)
	{
		comps.erase(comps.begin() + x);
	}

	void GameEngine::startGame(int character, Level* lev)
	{
		clear();
		c = character;
		l = lev;
		l->nextLevel();
		l->start();
	}
	void GameEngine::nextLevel()
	{
		gameOverMode = true;
		clear();
		
		if (l->getLev() >= l->getMaxLvl()) {
			l->next();
			gameOver();
			return;
		}
		delete p;
		l->nextLevel();
	}

	void GameEngine::gameOver()
	{
		gameOverMode = true;
		clear();
		l->gameOver();
	}
	void GameEngine::add(Sprite* s) {
		comps.push_back(s);
	}
	void GameEngine::addPowerUp(PowerUp* p) {
		comps.push_back(p);
		powerUps.push_back(p);
	}
	void GameEngine::addPlayer(Player* player) {
		p = player;
		comps.push_back(p);
	}
	void GameEngine::addEnemy(Enemy* enemy) {
		enemies.push_back(enemy);
		comps.push_back(enemy);
	}

	void GameEngine::run() {
		bool quit = false;
		const int tickInterval = 1000 / fps;
		int lapCount = 0;
		while (!quit) {
			gameOverMode = false;
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
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

			for (Enemy* e : enemies) {
				e->move();
				if (gameOverMode)
					break;
			}//for
			 //lägg till inlämningarna efter ett antal varv
			if (lapCount % 3000 == 0) {
				for (std::vector<PowerUp*>::iterator it = powerUps.begin();
					it != powerUps.end(); ++it) {
					if (!(std::find(comps.begin(), comps.end(), *it) != comps.end())) {
						std::cout << *it;
						comps.push_back(*it);
					}
				}
			}

			SDL_SetRenderDrawColor(eng.getRen(), 0, 0, 0, 255);
			SDL_RenderClear(eng.getRen());
			for (Sprite* s : comps) {
				s->draw();
			}//for
			p->draw();

			SDL_RenderPresent(eng.getRen());
			std::cout << lapCount << " ";
			lapCount++;
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} //yttre while

	}
	void GameEngine::clear()
	{
		//lägg till allt om det inte finns
		for (std::vector<PowerUp*>::iterator it = powerUps.begin();
			it != powerUps.end(); ++it) {
			if (!(std::find(comps.begin(), comps.end(), *it) != comps.end())) {
				std::cout << *it;
				comps.push_back(*it);
			}
		}

		for (std::vector<Sprite*>::iterator it = comps.begin();
			it != comps.end(); ++it) {
			Player *p;
			if (!(p = dynamic_cast<Player *>(*it))) {
				delete *it;
			}
		}
		comps.clear();
		enemies.clear();
		powerUps.clear();
	}
	GameEngine eng;
}

