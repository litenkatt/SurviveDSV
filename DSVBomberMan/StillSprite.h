#ifndef STILLSPRITE_H
#define STILLSPRITE_H
#include "Sprite.h"

namespace engine {
	class StillSprite : public Sprite
	{
	public:
		virtual ~StillSprite();
		virtual void draw() const = 0;
	protected:
		StillSprite(int x, int y);
	};
}


#endif