#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <vector>
#include "Sprite.h"

namespace engine {
	class GameLoop
	{
	public:
		void add(Sprite* s);
		void run();
		~GameLoop();
	private:
		std::vector<Sprite*> comps;
	};
}

#endif
