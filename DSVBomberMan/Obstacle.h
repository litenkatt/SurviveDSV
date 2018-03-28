#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "StillSprite.h"

	class Obstacle : public engine::StillSprite
	{
	public:
		static Obstacle* getInstance(int lev, int x, int y);
		~Obstacle();
		void draw() const;
	protected:
		Obstacle(int x, int y, int lev);
	private:
		SDL_Texture* green, *yellow, *red;
		int level;
	};

#endif

