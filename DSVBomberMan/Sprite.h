#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace engine {
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void draw() const = 0;
		const SDL_Rect& getRect() const { return rect; }
		void setX(int dif);
		void setY(int dif);
	protected:
		Sprite(int x, int y, int w, int h);
		
	private:
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;

	};//Sprite
}//engine

#endif

