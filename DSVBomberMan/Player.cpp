#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "GameEngine.h"


namespace engine {
	Player::Player(int x, int y, int w, int h) : MovingSprite(x, y, w, h)
	{

	}
	Player::~Player()
	{
	}


}

