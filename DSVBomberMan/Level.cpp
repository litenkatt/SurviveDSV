#include "Level.h"
#include "GameLoop.h"
#include "Player.h"
#include "Sprite.h"
#include "Obstacle.h"
#include "RemovableObstacle.h"
#include "Enemy.h"


using namespace engine;

namespace survivedsv {
	Level::Level(int lev)
	{
		loop = new GameLoop();
		Player* p = Player::getInstance();
		if (lev == 1) {
			Obstacle* o = Obstacle::getInstance(1);
			loop->add(o);
			RemovableObstacle* ro = RemovableObstacle::getInstance();
			loop->add(ro);
			Enemy* e = Enemy::getInstance();
			loop->add(e);
		}
		//loop->add(p);
		loop->addPlayer(p);
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

