#ifndef DSVPLAYER_H
#define DSVPLAYER_H
#include "Player.h"

namespace survivedsv {
	class DSVPlayer : public engine::Player
	{
	public:
		static DSVPlayer* getInstance(int pic);
		~DSVPlayer();
		void draw() const;
	protected:
		DSVPlayer(int x, int y, int w, int h, int pic);
	private:
		SDL_Texture* texture;
	};
}


#endif