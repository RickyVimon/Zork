#include "pch.h"
#include "Enemy.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Enemy::Enemy(string name, string description, Room* room) :
	Creature(name, description, room)
{
	SetStats(name);
}

void Enemy::SetStats(string name) {
	//read stats from the Bestiary files and set on this class parameter
	std::ifstream i("Bestiary.json");
	json j;
	i >> j;


}


Enemy::~Enemy()
{
}
