
#include "Button.h"
#include <SDL_ttf.h>
#include "GameEngine.h"
#include <SDL_image.h>
namespace engine {

	Button::Button(int x, int y, int w, int h, std::string but, std::string inBut) :Sprite(x, y, w, h)
	{
		upIcon = IMG_LoadTexture(eng.getRen(), but.c_str());
		downIcon = IMG_LoadTexture(eng.getRen(), inBut.c_str());
		
	}

	Button::~Button()
	{
		SDL_DestroyTexture(upIcon);
		SDL_DestroyTexture(downIcon);
	}

	Button* Button::getInstance(int x, int y, int w, int h, std::string but, std::string inBut) {
		return new Button(x, y, w, h, but, inBut);
	}

	void Button::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			isDown = true;
		}
			
	}
	void Button::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			perform(this);

		isDown = false;
	}
	void Button::draw() const {
		
		if (isDown)
			SDL_RenderCopy(eng.getRen(), downIcon, NULL, &getRect());
		else
			SDL_RenderCopy(eng.getRen(), upIcon, NULL, &getRect());

	}
}