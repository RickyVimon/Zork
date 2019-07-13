#pragma once
#include "Creature.h"

enum Hero_Class {
	BERSERKER,
	SLAYER,
	LANCER
};

class Player :
	public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();
	void SetStats(const char* name, Hero_Class role);
};

