#include "Sprite.h"
#include <SDL.h>

namespace engine {
	Sprite::Sprite(int x, int y, int w, int h) :rect{ x,y,w,h }
	{
	}


	Sprite::~Sprite()
	{
	}
}



