#ifndef PLAYER_H
#define PLAYER_H
#include "MovingSprite.h"

namespace engine {
	class Player : public engine::MovingSprite
	{
	public:
		static Player* getInstance();
		~Player();
		void draw() const;
	protected:
		Player(int x, int y, int w, int h);
	private:
		SDL_Texture* texture;
		SDL_Texture* upIcon, *downIcon;
	};
}

#endif


