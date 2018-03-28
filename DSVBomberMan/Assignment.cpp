#include "Assignment.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>



Assignment::Assignment(int x, int y) : PowerUp(x, y)
{
	texture = IMG_LoadTexture(eng.getRen(), "inlamning.png");
}

Assignment::~Assignment()
{
	SDL_DestroyTexture(texture);
}
void Assignment::draw() const
{
	SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
}
Assignment * Assignment::getInstance(int x, int y)
{
	return new Assignment(x, y);
}