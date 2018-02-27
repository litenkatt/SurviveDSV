#ifndef ENEMY_H
#define ENEMY_H
#include "MovingSprite.h"

namespace survivedsv {
	class Enemy : public engine::MovingSprite
	{
	public:
		static Enemy* getInstance();
		~Enemy();
		void draw() const;
	protected:
		Enemy(int x, int y, int w, int h);
	private:
		SDL_Texture* texture;
	};

}

#endif

