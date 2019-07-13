#pragma once
#include "Creature.h"

enum Hero_Class {
	BERSERKER,
	SLAYER,
	LANCER
};

class Player : public Creature
{
public:
	Player(string name, string description, Room* room);
	~Player();
	void SetStats(string name, Hero_Class role);
};

