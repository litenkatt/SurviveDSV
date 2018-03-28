#ifndef DSVLEVEL_H
#define DSVLEVEL_H
#include "Level.h"
#define FPS 60

using namespace engine;

class DSVLevel : public Level
{
public:
	DSVLevel();
	~DSVLevel();
	void nextLevel();
	void gameOver();
	int getMaxLvl() { return 3; }

};

#endif