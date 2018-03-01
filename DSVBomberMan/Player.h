#ifndef PLAYER_H
#define PLAYER_H
#include "MovingSprite.h"

namespace engine {
	class Player : public MovingSprite
	{
	public:
		~Player();
		virtual void draw() const = 0;
	protected:
		Player(int x, int y, int w, int h);
	};
}

#endif


