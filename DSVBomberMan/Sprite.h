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
		const int getX() const { return rect.x; }
		const int getY() const { return rect.y; }
		const int getW() const { return rect.w; }
		const int getH() const { return rect.h; }
	protected:
		Sprite(int x, int y, int w, int h);
	private:
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;

	};//Sprite
}//engine

#endif

