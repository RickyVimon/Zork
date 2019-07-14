#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, string description, Room* room) :
	Entity(name, description, (Entity*)room)
{

}


Creature::~Creature()
{
}

int Creature :: Roll(int max_num) {
	int result = (1 + rand() % max_num);
	return result;
}

int Creature::Attack(Item* weapon, Creature* enemy) {
	return 0;
}

void Creature::SetStats(string name) {

}
void Creature::SetMods() {
	str_mod = (str - 10) / 2;
	dex_mod = (dex - 10) / 2;
	con_mod = (con - 10) / 2;
}

