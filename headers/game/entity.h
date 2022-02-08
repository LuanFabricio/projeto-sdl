#ifndef ENTITY
#define ENTITY
#include "../common.h"
#include "../draw.h"
class Entity {
	public:
		Entity(char* name, int hp, int attack, int speed);
		~Entity();
		void move(int newX, int newY, Draw &draw);
		void takeDamage(int damage);
		int getHp(); 
		int getAttack(); 
		int getSpeed(); 
		bool isAlive();
		int x, y, index;
		char* name;
	private:
		bool alive = true;
		int _hp, _attack, _speed;
};
#endif
