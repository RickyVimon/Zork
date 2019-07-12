#include "pch.h"
#include "Player.h"


Player::Player(const char* name, const char* description, Room* room) :
	Creature(name, description, room)
{
}


Player::~Player()
{
}
