#ifndef CHOICEBUTTON_H
#define CHOICEBUTTON_H
#include <SDL.h>
#include <string>
#include "Sprite.h"
#include <string>


namespace engine {
	class ChoiceButton : public Sprite
	{
	public:
		static ChoiceButton* getInstance(int x, int y, int w, int h, std::string but, std::string inBut, std::string chosenBut);
		void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
		void draw() const;
		virtual void perform(ChoiceButton* source) {}
		~ChoiceButton();
	protected:
		ChoiceButton(int x, int y, int w, int h, std::string but, std::string inBut, std::string chosenBut);
	private:
		std::string text;
		SDL_Texture* icon, *chosenIcon, *downIcon;
		bool isChosen = false;
		bool isDown = false;
	};
}

#endif