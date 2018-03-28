#include "MovingSprite.h"
#include <SDL.h>
#include <vector>
#include <iostream>
#include "GameEngine.h"

namespace engine {

	MovingSprite::~MovingSprite()
	{
	}
	MovingSprite::MovingSprite(int x, int y, int w, int h, int speed) 
		: Sprite(x, y, w, h), speed(speed)
	{
		stepCount = 1;
		stepsLeft = speed;
		timer = -1;
	}

	void MovingSprite::resetSteps(int newTimer)
	{
		stepCount = 1;
		timer = newTimer;
	}

	void MovingSprite::updateThis()
	{
		thisTop = getRect().y;
		thisBottom = getRect().y + getRect().h;
		thisLeft = getRect().x;
		thisRight = getRect().x + getRect().w;
		if (stepCount % timer == 0) {
			stepCount = 1;
			stepAction();
		}
	}
	bool MovingSprite::checkLeft()
	{
		int pos = 0;
		for (Sprite* otherSprite : eng.getSprites()) {
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherTop = otherSprite->getRect().y;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;
			if ((thisLeft <= otherRight) && !(otherRight >= thisRight))
				if (((otherTop < thisBottom) && (otherTop > thisTop))
					|| ((otherBottom < thisBottom) && (otherBottom > thisTop))
					|| ((otherBottom >= thisBottom) && (otherTop <= thisTop))) {
					collision(pos, otherSprite);
					return true;
				}//if
			pos++;
		}//for
		return false;
	}
	bool MovingSprite::checkRight()
	{
		int pos = 0;
		for (Sprite* otherSprite : eng.getSprites()) {
			otherTop = otherSprite->getRect().y;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;
			otherLeft = otherSprite->getRect().x;
			if ((thisRight >= otherLeft) && !(otherLeft <= thisLeft))
				if (((otherTop < thisBottom) && (otherTop > thisTop))
					|| ((otherBottom < thisBottom) && (otherBottom > thisTop))
					|| ((otherBottom >= thisBottom) && (otherTop <= thisTop))) {
						collision(pos, otherSprite);
						return true;
						}//if
			pos++;
		}//for
		return false;
	}
	bool MovingSprite::checkUp()
	{
		int pos = 0;
		for (Sprite* otherSprite : eng.getSprites()) {
			otherLeft = otherSprite->getRect().x;
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;
			if ((thisTop <= otherBottom) && !(otherBottom >= thisBottom))
				if (((otherLeft > thisLeft) && (otherLeft < thisRight))
					|| ((otherRight < thisRight) && (otherRight > thisLeft))
					|| ((otherRight >= thisRight) && (otherLeft <= thisLeft))) {
						collision(pos, otherSprite);
						return true;
				}//if
			pos++;
		}//for
		return false;
	}
	bool MovingSprite::checkDown()
	{
		int pos = 0;
		for (Sprite* otherSprite : eng.getSprites()) {
			otherLeft = otherSprite->getRect().x;
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherTop = otherSprite->getRect().y;
			if ((thisBottom >= otherTop) && !(otherTop <= thisTop))
				if (((otherLeft > thisLeft) && (otherLeft < thisRight))
					|| ((otherRight < thisRight) && (otherRight > thisLeft))
					|| ((otherRight >= thisRight) && (otherLeft <= thisLeft))) {
						collision(pos, otherSprite);
						return true;
				}	
			pos++;
		}//for
		
		return false;
	}
	void MovingSprite::left() {
		stepCount++;
		if (!checkLeft()) {
			setX(-1);
			updateThis();
			if (stepsLeft != 0) {
				if (!checkUp() || !checkDown()) {
					stepsLeft = speed;
				}
				else {
					stepsLeft--;
					left();
				}	
			}
			else
				stepsLeft = speed;
		}
	};
	void MovingSprite::right() {
		stepCount++;
		if (!checkRight()) {
			setX(1);
			updateThis();
			if (stepsLeft != 0) {
				if (!checkUp() || !checkDown()) {
					stepsLeft = speed;
				}
				else {
					stepsLeft--;
					right();
				}
			}
			else
				stepsLeft = speed;
		}
	};
	void MovingSprite::up() {
		stepCount++;
		if (!checkUp()) {
			setY(-1);
			updateThis();
			if (stepsLeft != 0) {
				if (!checkLeft() || !checkRight()) {
					stepsLeft = speed;
				}
				else {
					stepsLeft--;
					up();
				}
			}
			else
				stepsLeft = speed;
		}
	};
	void MovingSprite::down() {
		stepCount++;
		if (!checkDown()) {
			setY(1);
			updateThis();
			if (stepsLeft != 0) {
				if (!checkLeft() || !checkRight()) {
					stepsLeft = speed;
				}
				else {
					stepsLeft--;
					down();
				}
			}
			else
				stepsLeft = speed;
		}
	};
}



