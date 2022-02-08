#include "../../headers/game/entity.h"

Entity::Entity(char* ent_name, int hp, int attack, int speed){
	_hp = hp;
	_attack = attack;
	_speed = speed;
	name = new char[strlen(ent_name)];
	strcpy(name, ent_name);
}

Entity::~Entity(){
	delete[] name;
}

void Entity::move(int newX, int newY, Draw &draw){
	_x = newX;
	_y = newY;
	draw.updateTextureCoords(index, newX, newY);
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
