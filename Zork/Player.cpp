
#include "pch.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


Player::Player(string name, string description, Room* room) :
	Creature(name, description, room)
{
	actualroom = room;
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
		heroclass = "Berserker";
		break;
	case SLAYER:
		str = 10;
		dex = 12;
		con = 8;
		heroclass = "Slayer";
		break;
	case LANCER:
		str = 10;
		dex = 8;
		con = 12;
		heroclass = "Lancer";
		break;
	}
	lvl = 1;
	SetMods();
	max_health = con * lvl;
	health = max_health;
	ac = 10;
	cout << "\n" << heroclass << " created succesfuly. You can take a look at your Stats.\n";
	PrintStats();
	cout << "Remember you can check your stats anytime with the command STATS.\n\n";
}
void Player::PrintStats() {
	cout << "\n-----------------------------\n";
	cout << name << " - " << "Level " << lvl << " - " << heroclass << ":\n";
	cout << "-----------------------------\n";

	cout << "Health Points: " << health << "/" << max_health << "\n";
	cout << "Armor: " << ac << "\n";
	cout << "Strength: " << str << "\n";
	cout << "Dexterity: " << dex << "\n";
	cout << "Constitution: " << con << "\n\n";

}

void Player::ChangeRoom(Exit* exit) {
	if (!exit->IsLocked()) {
		//Exit locked, you cant leave this room
	}
	actualroom = exit->NextRoom(GetRoom());

}

Room* Player::GetRoom() {
	return actualroom;
}

string Player::GetRoomName() {
	Room* r = GetRoom();
	return r->name;
}

bool Player::LeaveRoom(string direction, vector<Exit*> exits) {
	//find exits which have player->actualRoom as Origin room
	for (int i = 0; i < exits.size(); i++)
	{
		if (Universal::ToLowerString(exits[i]->CheckRoom(GetRoomName())) == direction) {
			//exit encontrada
			ChangeRoom(exits[i]);
			return true;
		}
	}
	return false;
	/*
	auto it = find_if(exits.begin(), exits.end(), [&roomname](const Exit& obj) {return obj. obj.GetOrigin()->name == roomname;});
	if (it != exits.end())
	{
		// found element. it is an iterator to the first matching element.
		// if you really need the index, you can also get it:
		auto index = std::distance(exits.begin(), it);
		// if (exittrobada.origin_direction == "direction"", player->actualRoom =  exittrobada.destinarionRoom)
		//ChangeRoom();
		return true;
	}
	else
		return false;
		*/
}