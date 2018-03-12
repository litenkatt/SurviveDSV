#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include <vector>

namespace engine {
	class MovingSprite : public Sprite
	{
	public:
		virtual ~MovingSprite();
		virtual void draw() const = 0;
		void left(std::vector<Sprite*>*);
		void right(std::vector<Sprite*>*);
		void up(std::vector<Sprite*>*);
		void down(std::vector<Sprite*>*);
		
	protected:
		MovingSprite(int x, int y, int w, int h);
	private:
		int thisTop, thisBottom, thisRight, thisLeft;
		int otherBottom, otherTop, otherRight, otherLeft;
		void updateThis();
		//bool checkCollision(Sprite*);
		//bool move(std::vector<Sprite*>*);
	};
}

#endif
