#include "../../headers/game/entity.h"

Entity::Entity(int hp, int attack, int speed){
	_hp = hp;
	_attack = attack;
	_speed = speed;
}

void Entity::takeDamage(int damage){
	_hp -= damage;
	if(_hp < 0){
		alive = false;
	}
}

bool Entity::isAlive(){
	return alive;
}

int Entity::getHp(){
	return _hp;
}

int Entity::getAttack(){
	return _attack;
}

int Entity::getSpeed(){
	return _speed;
}
