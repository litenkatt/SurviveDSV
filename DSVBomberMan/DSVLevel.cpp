#include "DSVLevel.h"
#include "Level.h"
#include "DSVPlayer.h"
#include "Sprite.h"
#include "Obstacle.h"
#include "Teacher.h"
#include "Assignment.h"
#include <iostream>
#include "GameEngine.h"
#include "Label.h"
#include <string>

using namespace std;

DSVLevel::DSVLevel()
{

}


DSVLevel::~DSVLevel()
{
}

void DSVLevel::nextLevel()
{
	next();
	Player* p = DSVPlayer::getInstance(eng.getCharacter(), 110, 110, 5, 2000);
	eng.addPlayer(p);
	int w = 0;
	int h = 0;
	for (int i = 40; i < eng.getWinW() - 50; i += 70) {
		for (int x = 40; x < eng.getWinH() - 100; x += 70) {
			if (i == 40 || x == 40
				|| i == eng.getWinW() - 110 || x == eng.getWinH() - 140
				|| (w % 2 == 0 || w % 5 == 0) && h % 2 == 0) {
				Sprite* o = Obstacle::getInstance(getLev(), i, x);
				eng.add(o);
			}//if
			w++;
		}//inre for
		h++;
	}// yttre for

	Enemy* e = Teacher::getInstance(530, 250, getLev() * 2);
	eng.addEnemy(e);

	if (getLev() == 2) {
		Enemy* e2 = Teacher::getInstance(530, 320, getLev() * 2);
		eng.addEnemy(e2);
	}
	else if (getLev() == 3) {
		Enemy* e3 = Teacher::getInstance(670, 250, getLev() * 2);
		eng.addEnemy(e3);
		
	}
	PowerUp* a = Assignment::getInstance(1020, 110);
	eng.addPowerUp(a);
}

void DSVLevel::gameOver()
{
	string grade;
	string text;
	if (getLev() == 1) {
		grade = "F";
		text = "Du blev underkänd!";
	}
	else if (getLev() == 2) {
		grade = "E";
		text = "Du blev godkänd!!";
	}
	else if (getLev() == 3) {
		grade = "C";
		text = "Bra gjort!!!!!!!";
	}
	else if (getLev() == 4) {
		grade = "A";
		text = "Wohoooooo!!!!!!!";
	}
	Label* lbl1 = Label::getInstance(350, 50, 400, 400, grade);
	Label* lbl2 = Label::getInstance(350, 470, 400, 100, text);
	eng.add(lbl1);
	eng.add(lbl2);
}
