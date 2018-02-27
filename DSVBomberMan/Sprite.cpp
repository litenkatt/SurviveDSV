#include "Sprite.h"
#include <SDL.h>

namespace engine {

	Sprite::~Sprite()
	{
	}

	void Sprite::setX(int dif)
	{
		rect.x = (rect.x) + dif;
	}

	void Sprite::setY(int dif)
	{
		rect.y = (rect.y) + dif;
	}

	Sprite::Sprite(int x, int y, int w, int h) : rect{ x,y,w,h }
	{
	}
}



