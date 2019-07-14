
#include "pch.h"
#include "Player.h"
#include <iostream>


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
	cout << name << " - " << "Level " << lvl << " - "<< heroclass << ":\n";
	cout << "-----------------------------\n";

	cout << "Health Points: " << health << "/" << max_health << "\n";
	cout << "Armor: " << ac << "\n";
	cout << "Strength: " << str << "\n";
	cout << "Dexterity: " << dex << "\n";
	cout << "Constitution: " << con << "\n\n";		

