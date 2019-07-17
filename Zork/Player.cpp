
#include "pch.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


Player::Player(string name, string description, Room* room) :
	Creature(name, description, room)
{
	type = PLAYER;
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
	stats.emplace("Armor", str);
	stats.emplace("Dexterity", dex);
	stats.emplace("Constitution", con);
	stats.emplace("Armor", ac);
	stats.emplace("Health", health);
	stats.emplace("MaxHealth", max_health);
	stats.emplace("Level", lvl);
	stats.emplace("Experience", exp);


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
	if (!exit->locked) {
	cout << "Exit locked, you need to find the way to unlock it. \n";
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

bool Player::LeaveRoom(string direction) {
	//find exits which have player->actualRoom as Origin room
	vector<Exit*> exits = actualroom->GetExits();
	for (size_t i = 0; i < exits.size(); i++)
	{
		if (Universal::ToLowerString(exits[i]->CheckRoom(GetRoomName())) == direction) {
			//exit encontrada
			if (!exits[i]->locked) {
				cout << "\n The " << exits[i]->name << " is locked, you should find the way to unlock it.\n";
				return false;
			}				
			ChangeRoom(exits[i]);
			return true;
		}
		cout << "\n" << GetRoom()->name << " has no exit on the " << direction << ".\n";
	}
	return false;
}