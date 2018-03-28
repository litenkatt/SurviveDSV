#ifndef DSVPLAYER_H
#define DSVPLAYER_H
#include "Player.h"

	class DSVPlayer : public engine::Player
	{
	public:
		static DSVPlayer* getInstance
		(int pic, int x, int y, int speed, int superTime);
		~DSVPlayer();
		void draw() const;
	protected:
		
	private:
		DSVPlayer(int x, int y, int pic, int speed, int superTime);
		SDL_Texture* texture, *assText;
	};

#endif