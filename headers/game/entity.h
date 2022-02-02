#ifndef ENTITY
#define ENTITY
#include "../common.h"
class Entity {
	public:
		Entity(int hp, int attack, int speed);
		void setPosition(int x, int y);
		void setTexture(SDL_Texture texture);
		void takeDamage(int damage);
		int getHp(); 
		int getAttack(); 
		int getSpeed(); 
		bool isAlive();
	private:
		bool alive = true;
		int _hp, _attack, _speed, _x, _y, _index;
};
#endif
