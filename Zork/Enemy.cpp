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
	type = ENEMY;
}


Enemy::~Enemy()
{
}

void Enemy::SetStats(string name) {
	//read stats from the Bestiary files and set on this class parameter
	std::ifstream i("Bestiary.json");
	json j;
	i >> j;
	try {
		auto bestiary = j[name];
		lvl = bestiary["lvl"];
		str = bestiary["str"];
		dex = bestiary["dex"];
		con = bestiary["con"];
		exp = bestiary["exp"];
		ac = bestiary["ac"];
		max_health = con * lvl;
		SetMods();
		health = max_health;
	}
	catch (exception) {
		//enemy not found
	}
}