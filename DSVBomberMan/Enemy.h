#ifndef ENEMY_H
#define ENEMY_H
#include "MovingSprite.h"

namespace engine {
	class Enemy : public engine::MovingSprite
	{
	public:
		~Enemy();
		virtual void move() = 0;
		void collision(int, Sprite*);
	protected:
		Enemy(int x, int y, int speed);
	private:
		Enemy(const Enemy&) = delete;
		const Enemy& operator=(const Enemy&) = delete;
		virtual void draw() const = 0;
	};

}

#endif

