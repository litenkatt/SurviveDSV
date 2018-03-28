#include "Teacher.h"
#include "Enemy.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

using namespace engine;

	Teacher::Teacher(int x, int y, int speed) : Enemy(x, y, speed)
	{
		SDL_Surface* surf = IMG_Load("enemy.png");
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);
		dir = 0;
	}
	Teacher * Teacher::getInstance(int x, int y, int speed)
	{
		return new Teacher(x, y, speed);
	}
	Teacher::~Teacher()
	{
		SDL_DestroyTexture(texture);
	}
	void Teacher::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}

	void Teacher::move()
	{
		if (dir == 0 && !checkDown()) {
			down();
			return;
		}
		
		if (dir == 1 && !checkUp()) {
			up();
			return;
		}

		if (dir == 2 && !checkRight()) {
			right();
			return;
		}

		if (dir == 3 && !checkLeft()) {
			left();
			return;
		}
		
			dir = rand() % 4;
		
			
	}
