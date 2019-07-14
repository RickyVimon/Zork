
#include "pch.h"
#include "Player.h"


Player::Player(string name, string description, Room* room) :
	Creature(name, description, room)
{
}


Player::~Player()
{
}

void Player::SetStats(string name, Hero_Class role)
{
	switch (role) {
	case BERSERKER:
		str = 12;
		dex = 8;
		con = 10;
		break;
	case SLAYER:
		str = 10;
		dex = 12;
		con = 8;
		break;
	case LANCER:
		str = 10;
		dex = 8;
		con = 12;
		break;
	}
	lvl = 1;
	SetMods();
	max_health = con * lvl;
	health = max_health;
	ac = 10;

}