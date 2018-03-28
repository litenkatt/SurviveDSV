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
		void left();
		void right();
		void up();
		void down();
	protected:
		MovingSprite(int x, int y, int w, int h, int speed);
		virtual void collision(int, Sprite*) {}
		void resetSteps(int timer);
		virtual void stepAction(){}
		bool checkLeft();
		bool checkRight();
		bool checkUp();
		bool checkDown();
	private:

		int thisTop, thisBottom, thisRight, thisLeft;
		int otherBottom, otherTop, otherRight, otherLeft;
		
		void updateThis();
		MovingSprite(const MovingSprite&) = delete;
		const MovingSprite& operator=(const MovingSprite&) = delete;
		int stepCount;
		int speed;
		int stepsLeft;
		int timer;
	};
}

#endif
