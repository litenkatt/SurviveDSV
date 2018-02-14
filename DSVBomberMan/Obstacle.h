#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "StillSprite.h"

namespace survivedsv {
	class Obstacle : public engine::StillSprite
	{
	public:
		static Obstacle* getInstance(int x, int y, int w, int h);
		~Obstacle();
	protected:
		Obstacle(int x, int y, int w, int h);
	};

}

#endif

