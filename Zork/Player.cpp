#include "pch.h"
#include "Player.h"


Player::Player(const char* name, const char* description, Room* room) :
	Creature(name, description, room)
{
}


Player::~Player()
{
}

void Player::SetStats(const char* name, Hero_Class role)
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

	int str_mod = (str - 10) / 2;
	int dex_mod = (dex - 10) / 2;
	int con_mod = (con - 10) / 2;

	max_health = con * 2;
	health = max_health;
	ac = 10;

}
