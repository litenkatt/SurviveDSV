#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"

namespace engine {
	class MovingSprite : public Sprite
	{
	public:
		virtual ~MovingSprite();
		virtual void draw() const = 0;
	protected:
		MovingSprite(int x, int y, int w, int h);
	};
}

#endif
