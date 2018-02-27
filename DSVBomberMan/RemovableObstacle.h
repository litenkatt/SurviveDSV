#ifndef REMOVABLEOBSTACLE_H
#define REMOVABLEOBSTACLE_H
#include "StillSprite.h"

namespace survivedsv {
	class RemovableObstacle : public engine::StillSprite
	{
	public:
		static RemovableObstacle* getInstance();
		~RemovableObstacle();
	protected:
		RemovableObstacle(int x, int y, int w, int h);
		void draw() const;
	private:
		SDL_Texture* texture;
	};
}

#endif
