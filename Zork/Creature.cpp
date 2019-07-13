#include "pch.h"
#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* room) :
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

void Creature::SetStats(const char* name) {

}
