#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, string description, Room* room) :
	Entity(name, description, (Entity*)room)
{

}


Creature::~Creature()
{
}

int Creature::Roll(int max_num) {
	int result = rand() % max_num + 1;

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

void Creature::AutoEquip(Item* item) {
	
}
void Creature::Drop(Item* item) {
	inventory.remove(item);
	item->parent = (Entity*)room;
}
void Creature::Take(Item* item) {
	item->parent = (Entity*)this;
	inventory.push_back(item);
	cout << "\n" << item->name << "is now in your inventory.\n";
}
void Creature::Equip(Item* item) {

}
void Creature::Unequip(Item* item) {

}

vector<Item*> Creature::GetItems() {
	vector<Item*> out;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (ent->type = ITEM) {
			out.push_back(ent);
		}
	}
	return out;
}

void Creature::UpdateStats(string stats_name, int value) {
	stats.find(stats_name)->second = stats.find(stats_name)->second + value;
}

