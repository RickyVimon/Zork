#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(const char* name, const char* description, Room* room) :
	Creature(name, description, room)
{
	this->SetStats(name);
}

void Enemy::SetStats(const char* name) {
	//read stats from the Bestiary files and set on this class parameter
}


Enemy::~Enemy()
{
}
