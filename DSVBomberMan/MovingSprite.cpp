#include "MovingSprite.h"
#include <SDL.h>
#include <vector>
#include <iostream>

namespace engine {

	MovingSprite::~MovingSprite()
	{
	}
	MovingSprite::MovingSprite(int x, int y, int w, int h) : Sprite(x, y, w, h)
	{

	}
	void MovingSprite::updateThis()
	{
		thisTop = getRect().y;
		thisBottom = getRect().y + getRect().h;
		thisLeft = getRect().x;
		thisRight = getRect().x + getRect().w;
	}
	//bool MovingSprite::checkCollision(Sprite* otherSprite)
	//{
	//	//The sides of the rectangles
	//	int thisLeft, otherLeft;
	//	int thisRight, otherRight;
	//	int thisTop, otherTop;
	//	int thisBottom, otherBottom;

	//	//Calculate the sides of rect A
	//	//thisLeft = this->getRect().x;
	//	thisRight = this->getRect().x + this->getRect().w;
	//	thisTop = this->getRect().y;
	//	thisBottom = this->getRect().y + this->getRect().h;

	//	//Calculate the sides of rect B
	//	otherLeft = otherSprite->getRect().x;
	//	//otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
	//	otherTop = otherSprite->getRect().y;
	//	otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;

	//	//If any of the sides from A are outside of B
	//	if (thisBottom <= otherTop)
	//	{
	//		return false;
	//	}

	//	if (thisTop >= otherBottom)
	//	{
	//		return false;
	//	}

	//	if (thisRight <= otherLeft)
	//	{
	//		return false;
	//	}

	//	if (thisLeft >= otherRight)
	//	{
	//		return false;
	//	}

	//	//If none of the sides from A are outside B
	//	return true;
	//}
	//bool MovingSprite::move(std::vector<Sprite*>* otherSprites) {
	//	for (Sprite* s : *otherSprites) {
	//		if (checkCollision(s)) {
	//			return true;
	//		}
	//	}//for
	//	return false;
	//}

	void MovingSprite::left(std::vector<Sprite*>* otherSprites) {
		
		bool col = false;
		for (Sprite* otherSprite : *otherSprites) {
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherTop = otherSprite->getRect().y;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;
			//otherLeft = otherSprite->getRect().x;
			if ((thisLeft <= otherRight) && !(otherRight >= thisRight))
				if (((otherTop < thisBottom) && (otherTop > thisTop))
					|| (otherBottom < thisBottom) && (otherBottom > thisTop)
						|| (otherBottom == thisBottom) && (otherTop == thisTop))
							col = true;
				
				
		}//for
		if (!col) {
			setX(-1);
			updateThis();
		}
			

	};
	void MovingSprite::right(std::vector<Sprite*>* otherSprites) {
		
		bool col = false;
		for (Sprite* otherSprite : *otherSprites) {
			//otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherTop = otherSprite->getRect().y;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;
			otherLeft = otherSprite->getRect().x;
			if ((thisRight >= otherLeft) && !(otherLeft <= thisLeft))
				if (((otherTop < thisBottom) && (otherTop > thisTop))
					|| (otherBottom < thisBottom) && (otherBottom > thisTop)
						|| (otherBottom == thisBottom) && (otherTop == thisTop))
							col = true;
		}//for
		if (!col) {
			setX(1);
			updateThis();
		}
			

	};
	void MovingSprite::up(std::vector<Sprite*>* otherSprites) {
		
		bool col = false;
		for (Sprite* otherSprite : *otherSprites) {
			otherLeft = otherSprite->getRect().x;
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherBottom = otherSprite->getRect().y + otherSprite->getRect().h;

			if ((thisTop <= otherBottom) && !(otherBottom >= thisBottom))
				if (((otherLeft > thisLeft) && (otherLeft < thisRight))
					|| (otherRight < thisRight) && (otherRight > thisLeft)
						|| (otherRight == thisRight) && (otherLeft == thisLeft))
							col = true;
		}//for
		if (!col) {
			setY(-1);
			updateThis();
		}
			
	};
	void MovingSprite::down(std::vector<Sprite*>* otherSprites) {
		
		bool col = false;
		for (Sprite* otherSprite : *otherSprites) {
			otherLeft = otherSprite->getRect().x;
			otherRight = otherSprite->getRect().x + otherSprite->getRect().w;
			otherTop = otherSprite->getRect().y;

			if ((thisBottom >= otherTop) && !(otherTop <= thisTop))
				if (((otherLeft > thisLeft) && (otherLeft < thisRight))
					|| (otherRight < thisRight) && (otherRight > thisLeft)
						||(otherRight==thisRight) && (otherLeft==thisLeft))
							col = true;
		}//for
		if (!col) {
			setY(1);
			updateThis();
		}
			
	};
}



