#include "Label.h"
#include <SDL_ttf.h>
#include "GameEngine.h"
#include <iostream>
#include <string>
using namespace std;

namespace engine {

	Label* Label::getInstance(int x, int y, int w,
		int h, std::string txt) {
		return new Label(x, y, w, h, txt);
	}

	Label::Label(int x, int y, int w, int h,
		std::string txt) : Sprite(x, y, w, h), text(txt)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(eng.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	void Label::draw() const {
		SDL_RenderCopy(eng.getRen(), texture, NULL, &getRect());
	}

	Label::~Label()
	{
		SDL_DestroyTexture(texture);
	}

	string Label::getText() const {
		return text;
	}
	void Label::setText(std::string newText) {
		text = newText;
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(eng.getFont(),
			text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
		SDL_FreeSurface(surf);
	}
}