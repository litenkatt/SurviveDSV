#include "Level.h"
#include "GameLoop.h"
#include "Player.h"
#include "Sprite.h"


using namespace engine;

namespace survivedsv {
	Level::Level(int lev)
	{
		loop = new GameLoop();
		Player* p = Player::getInstance();
		loop->add(p);
	}

	void Level::start()
	{
		loop->run();
	}

	void Level::add(Sprite* s)
	{
		loop->add(s);
	}


	Level::~Level()
	{
	}
}

