#ifndef LEVEL_H
#define LEVEL_H
#include "GameLoop.h"
#include "Sprite.h"


namespace survivedsv {
	class Level
	{
	public:
		Level(int lev, int character);
		void start();
		void add(engine::Sprite* s);
		void addPlayer(engine::Player* p);
		~Level();
	private:
		engine::GameLoop* loop;
	};
}

#endif


