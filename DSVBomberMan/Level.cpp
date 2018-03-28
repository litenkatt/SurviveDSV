#include "Level.h"
#include "GameEngine.h"
#include "DSVPlayer.h"
#include "Sprite.h"
#include "Obstacle.h"
#include "Teacher.h"
#include "Assignment.h"
#include <iostream>
#include "GameEngine.h"

namespace engine {
	Level::Level()
	{
		lev = 0;
	}
	void Level::start()
	{
		eng.run();
	}

	Level::~Level()
	{
	}
}

