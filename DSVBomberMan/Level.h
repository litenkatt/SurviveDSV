#ifndef LEVEL_H
#define LEVEL_H
#include "GameLoop.h"


namespace survivedsv {
	class Level
	{
	public:
		Level(int lev);
		void start();
		~Level();
	private:
		engine::GameLoop* loop;
	};
}

#endif


