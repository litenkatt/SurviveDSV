#include "Level.h"
#include "GameLoop.h"
#include "DSVPlayer.h"
#include "Sprite.h"
#include "Obstacle.h"
#include "RemovableObstacle.h"
#include "Enemy.h"
#include <iostream>


using namespace engine;

namespace survivedsv {
	Level::Level(int lev, int character)
	{
		loop = new GameLoop();
		DSVPlayer* p = DSVPlayer::getInstance(character);
		loop->addPlayer(p);
		std::cout << p;

		if (lev == 1) {
			Obstacle* o = Obstacle::getInstance(1);
			loop->add(o);
			RemovableObstacle* ro = RemovableObstacle::getInstance();
			loop->add(ro);
			Enemy* e = Enemy::getInstance();
			loop->add(e);
		}
		
	}

	void Level::start()
	{
		loop->run();
	}

	void Level::add(Sprite* s)
	{
		loop->add(s);
	}
	void Level::addPlayer(Player* p)
	{
		loop->addPlayer(p);
	}


	Level::~Level()
	{
	}
}

