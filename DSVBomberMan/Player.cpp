#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "GameEngine.h"


namespace engine {
	Player::Player(int x, int y, int w, int h) : MovingSprite(x, y, w, h)
	{
		SDL_Surface* surf = IMG_Load("player.png"); 
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);

	}
	Player * Player::getInstance()
	{
		return new Player(300, 100, 100, 100);
	}
	Player::~Player()
	{
		SDL_DestroyTexture(texture);
	}
	void Player::draw() const
	{
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}

}

