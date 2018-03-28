#include "StillSprite.h"
#include <SDL.h>
#include "GameEngine.h"

namespace engine {

	StillSprite::~StillSprite()
	{
	}
	StillSprite::StillSprite(int x, int y) : 
		Sprite(x, y, eng.getTileSize(), eng.getTileSize())
	{
	}

}