#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <vector>
#include "Sprite.h"
#include "Player.h"

namespace engine {
	class GameLoop
	{
	public:
		void add(Sprite* s);
		void addPlayer(Player* player);
		void run();
		~GameLoop();
	private:
		std::vector<Sprite*> comps;
		Player* p;
	};
}

#endif
