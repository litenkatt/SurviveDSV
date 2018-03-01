#include "ChoiceButton.h"
#include <SDL_ttf.h>
#include "GameEngine.h"
#include <SDL_image.h>
namespace engine {

	ChoiceButton::ChoiceButton(int x, int y, int w, int h, std::string but, std::string inBut, std::string chosenBut) 
		:Sprite(x, y, w, h)
	{
		icon = IMG_LoadTexture(eng.getRen(), but.c_str());
		downIcon = IMG_LoadTexture(eng.getRen(), inBut.c_str());
		chosenIcon = IMG_LoadTexture(eng.getRen(), chosenBut.c_str());

	}

	ChoiceButton::~ChoiceButton()
	{
		SDL_DestroyTexture(icon);
		SDL_DestroyTexture(downIcon);
		SDL_DestroyTexture(chosenIcon);
	}

	ChoiceButton* ChoiceButton::getInstance(int x, int y, int w, int h, std::string but, std::string inBut, std::string chosenBut) {
		return new ChoiceButton(x, y, w, h, but, inBut, chosenBut);
	}

	void ChoiceButton::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			isDown = true;
		}

	}
	void ChoiceButton::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			perform(this);
			isDown = false;
			isChosen = true;
		}else {
			isChosen = false;
		}
			
	}
	void ChoiceButton::draw() const {

		if (isChosen)
			SDL_RenderCopy(eng.getRen(), chosenIcon, NULL, &getRect());
		else if (isDown)
			SDL_RenderCopy(eng.getRen(), downIcon, NULL, &getRect());
		else
			SDL_RenderCopy(eng.getRen(), icon, NULL, &getRect());

	}
}