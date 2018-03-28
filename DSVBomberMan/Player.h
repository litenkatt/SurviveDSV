#ifndef PLAYER_H
#define PLAYER_H
#include "MovingSprite.h"

namespace engine {
	class Player : public MovingSprite
	{
	public:
		~Player();
		virtual void draw() const = 0;
		const bool getMode() const { return superMode; }
	protected:
		Player(int x, int y, int speed, int superTime);
		void collision(int, Sprite*);
		
		virtual void stepAction() {	superMode = false; }
	private:
		Player(const Player&) = delete;
		const Player& operator=(const Player&) = delete;
		bool superMode;
		int superTime;
		//static Uint32 stopSuper(Uint32 interval, void *param);

	};
}

#endif


