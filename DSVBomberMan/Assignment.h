#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "PowerUp.h"

using namespace engine;

class Assignment : public PowerUp
{
	public:
		static Assignment* getInstance(int x, int y);
		~Assignment();
		void draw() const;
	protected:
		Assignment(int x, int y);
	private:
		SDL_Texture* texture;
};

#endif