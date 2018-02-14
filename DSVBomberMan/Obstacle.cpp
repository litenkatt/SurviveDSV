#include "Obstacle.h"


namespace survivedsv {
	Obstacle * Obstacle::getInstance(int x, int y, int w, int h)
	{
		return nullptr;
	}
	Obstacle::~Obstacle()
	{
	}
	Obstacle::Obstacle(int x, int y, int w, int h) : StillSprite(x, y, w, h)
	{
	}
}

