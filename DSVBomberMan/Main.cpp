#include <SDL.h>
#include <iostream>
#include "Level.h"
#include <string>
#include "GameEngine.h"
#include "GameLoop.h"
#include "Label.h"
#include "Button.h"
#include <SDL.h>
#include <string>
using namespace std;
using namespace survivedsv;
using namespace engine;

bool quit = false;

class StartButton : public Button {
public:
	StartButton(int x, int y, int w, int h) :Button(x, y, w, h), level() {}
	void perform(Button* source) {
		cout << "mjaaaaaauuuuuu";
		quit = true;
		Level lev(1);
		lev.start();
	}
private:
	Level* level;
};

int main(int argc, char** argv) {


	SDL_SetRenderDrawColor(eng.getRen(), 150, 0, 150, 255);
	SDL_RenderClear(eng.getRen());
	Label* lbl = Label::getInstance(150, 30, 300, 100, "Tryck på knappen för att starta!");
	lbl->draw();
	Button* b = new StartButton(200, 150, 200, 200);
	b->draw();
	SDL_RenderPresent(eng.getRen());

	
	while (!quit) {
		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {
			switch (eve.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				b->mouseDown(eve);
				SDL_RenderClear(eng.getRen());
				lbl->draw();
				b->draw();
				SDL_RenderPresent(eng.getRen());
				break;
			case SDL_MOUSEBUTTONUP:
				b->mouseUp(eve);
				b->draw();
				break;

			} // switch
		} // inre while
	}



	
	




	return 0;
}