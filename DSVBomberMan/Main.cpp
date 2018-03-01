#include <SDL.h>
#include <iostream>
#include "Level.h"
#include <string>
#include "GameEngine.h"
#include "GameLoop.h"
#include "Label.h"
#include "Button.h"
#include "ChoiceButton.h"
#include <SDL.h>
#include <string>
using namespace std;
using namespace survivedsv;
using namespace engine;

bool quit = false;
int character = 1;

class StartButton : public Button {
public:
	StartButton(int x, int y, int w, int h) :Button(x, y, w, h, "button.png", "pressedbutton.png"), level() {}
	void perform(Button* source) {
		quit = true;
		Level lev(1, character);
		lev.start();
	}
private:
	Level* level;
};

class MarcusButton : public ChoiceButton {
public:
	MarcusButton(int x, int y, int w, int h) 
		:ChoiceButton(x, y, w, h, "marcus.png", "inmarcus.png", "chosenmarcus.png") {}
	void perform(ChoiceButton* source) {
		character = 1;
	}
private:
	Level* level;
};

class NinniButton : public ChoiceButton {
public:
	NinniButton(int x, int y, int w, int h)
		:ChoiceButton(x, y, w, h, "ninni.png", "inninni.png", "chosenninni.png") {}
	void perform(ChoiceButton* source) {
		character = 2;
	}
private:
	Level* level;
};

class ToveButton : public ChoiceButton {
public:
	ToveButton(int x, int y, int w, int h)
		:ChoiceButton(x, y, w, h, "tove.png", "intove.png", "chosentove.png") {}
	void perform(ChoiceButton* source) {
		character = 3;
	}
private:
	Level* level;
};

int main(int argc, char** argv) {

	std::vector<Sprite*> stuff;


	Label* lbl = Label::getInstance(450, 50, 300, 100, "Tryck på knappen för att starta!");
	ChoiceButton* m = new MarcusButton(300, 150, 200, 200);
	NinniButton* n = new NinniButton(500, 150, 200, 200);
	ChoiceButton* t = new ToveButton(700, 150, 200, 200);
	Button* b = new StartButton(500, 350, 200, 200);
	stuff.push_back(lbl);
	stuff.push_back(m);
	stuff.push_back(n);
	stuff.push_back(t);
	stuff.push_back(b);


	
	while (!quit) {
		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {
			switch (eve.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				b->mouseDown(eve);
				m->mouseDown(eve);
				n->mouseDown(eve);
				t->mouseDown(eve);
				/*SDL_RenderClear(eng.getRen());
				lbl->draw();
				m->draw();
				n->draw();
				t->draw();
				b->draw();
				SDL_RenderPresent(eng.getRen());*/
				break;
			case SDL_MOUSEBUTTONUP:
				m->mouseUp(eve);
				n->mouseUp(eve);
				t->mouseUp(eve);
				b->mouseUp(eve);
				/*SDL_RenderClear(eng.getRen());
				lbl->draw();
				m->draw();
				n->draw();
				t->draw();
				b->draw();
				SDL_RenderPresent(eng.getRen());*/
				break;

			} // switch
		} // inre while
		SDL_SetRenderDrawColor(eng.getRen(), 0, 0, 0, 255);
		SDL_RenderClear(eng.getRen());
		for (Sprite* s : stuff)
			s->draw();
		SDL_RenderPresent(eng.getRen());
	}



	
	




	return 0;
}