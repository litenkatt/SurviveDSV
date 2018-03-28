#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include <SDL_ttf.h>
#include "Level.h"
#include "PowerUp.h"
#include "Player.h"
#include "Enemy.h"

namespace engine {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();		
		SDL_Renderer* getRen() const;
		TTF_Font* getFont() const;
		int getCharacter() const;
		int getTileSize() const;
		int getWinW() const;
		int getWinH() const;
		std::vector<Sprite*> getSprites() const;
		void setFPS(int newFps) { fps = newFps; }
		void deleteSprite(int x);
		void startGame(int character, Level* lev);
		void nextLevel();
		void gameOver();
		void add(Sprite* s);
		void addPowerUp(PowerUp * p);
		void addPlayer(Player* player);
		void addEnemy(Enemy * enemy);
		void run();
	private:
		int fps = 60;
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
		int tileSize = 70;
		int winW = 1200;
		int winH = 600;
		Level* l;
		int levelN;
		int c;
		bool gameOverMode;
		std::vector<Sprite*> comps;
		std::vector<PowerUp*> powerUps;
		std::vector<Enemy*> enemies;
		Player* p;
		void clear();
	};

	extern GameEngine eng;
	
}

#endif
