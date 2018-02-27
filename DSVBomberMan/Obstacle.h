#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "StillSprite.h"

namespace survivedsv {
	class Obstacle : public engine::StillSprite
	{
	public:
		static Obstacle* getInstance(int lev);
		~Obstacle();
	protected:
		Obstacle(int x, int y, int w, int h, int lev);
		void draw() const;
	private:
		SDL_Texture* green, *yellow, *red;
		int level;
	};

}

#endif

