#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"

namespace engine {
	class MovingSprite : public Sprite
	{
	public:
		virtual ~MovingSprite();
		virtual void draw() const = 0;
		void left() { setX(-1); };
		void right() { setX(1); };
		void up() { setY(-1); };
		void down() { setY(1); };
	protected:
		MovingSprite(int x, int y, int w, int h);

	};
}

#endif
