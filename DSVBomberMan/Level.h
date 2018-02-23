#ifndef LEVEL_H
#define LEVEL_H
#include "GameLoop.h"
#include "Sprite.h"


namespace survivedsv {
	class Level
	{
	public:
		Level(int lev);
		void start();
		void add(engine::Sprite* s);
		~Level();
	private:
		engine::GameLoop* loop;
	};
}

#endif


