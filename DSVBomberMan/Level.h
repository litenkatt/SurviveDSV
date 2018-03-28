#ifndef LEVEL_H
#define LEVEL_H
#include "Sprite.h"


namespace engine {
	class Level
	{
	public:
		void start();
		virtual void nextLevel() = 0;
		virtual void gameOver() = 0;
		virtual int getMaxLvl() = 0;
		int getLev() { return lev; }
		void next() { lev++; }
		~Level();
	protected:
		Level();
	private:
		int lev;
	};
}

#endif


