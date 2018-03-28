#ifndef POWERUP_H
#define POWERUP_H
#include "StillSprite.h"

namespace engine {
	class PowerUp : public StillSprite
	{
	public:
		~PowerUp();
		virtual void draw() const = 0;
	protected:
		PowerUp(int x, int y);

	};
}


#endif
