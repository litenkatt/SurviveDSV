#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SDL_ttf.h>

namespace engine {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();		
		SDL_Renderer* getRen() const;
		TTF_Font* getFont() const;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
	};

	extern GameEngine eng;
	
}

#endif
