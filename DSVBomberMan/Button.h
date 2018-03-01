#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <string>
#include "Sprite.h"
#include <string>

namespace engine {
	class Button : public Sprite
	{
	public:
		static Button* getInstance(int x, int y, int w, int h, std::string but, std::string inBut);
		void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
		void draw() const;
		virtual void perform(Button* source) {}
		~Button();
	protected:
		Button(int x, int y, int w, int h, std::string but, std::string inBut);
	private:
		std::string text;
		SDL_Texture* upIcon, *downIcon;
		bool isDown = false;
	};
}
#endif