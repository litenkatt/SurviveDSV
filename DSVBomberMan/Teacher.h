#ifndef TEACHER_H
#define TEACHER_H
#include "Enemy.h"

	class Teacher : public engine::Enemy
	{
	public:
		static Teacher* getInstance(int, int, int);
		~Teacher();
		void draw() const;
		void move();
	protected:
		Teacher(int x, int y, int speed);
	private:
		SDL_Texture* texture;
		Teacher(const Enemy&) = delete;
		const Enemy& operator=(const Enemy&) = delete;
		int dir;
	};



#endif