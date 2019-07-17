#include "pch.h"
#include "Creature.h"
#include <algorithm>
#include "Universal.h"


Creature::Creature(string name, string description, Room* room) :
	Entity(name, description, (Entity*)room)
{
	actualroom = room;
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
	item->parent = (Entity*)actualroom;
	actualroom->container.push_back(item);
	container.erase(std::remove(container.begin(), container.end(), (Entity*)item), container.end());
	cout << "\nYour dropeed a " << item->name << ".\n";
}
void Creature::Take(Item* item) {
	item->parent = (Entity*)this;
	container.push_back(item);
	cout << "\n" << item->name << " is now in your inventory.\n";
}
void Creature::Equip(string itemname) {
	Item* item = GetItems(itemname);
	if (item != NULL) {
		if (!IsEquipped(itemname)) {
			item->EquipItem();
			equiped.push_back(item);
		}
		else
			cout << item->name << " is alredy equiped.\n";
	}
	else
	{
		cout << "You can't equip an item you don't have in your inventory.\n";
	}
}
void Creature::Unequip(Item* item) {

}

bool Creature::IsEquipped(string itemname) {
	for (std::list<Item*>::iterator it = equiped.begin(); it != equiped.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (Universal::ToLowerString(ent->name) == itemname) {
			return true;
		}
	}
	return false;
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

Item* Creature::GetItems(string name) {
	Item* out = NULL;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (ent->type == ITEM && Universal::ToLowerString(ent->name) == name) {
			out = ent;
			return out;
		}
	}
	return out;
}

vector<string> Creature::GetItemsNames() {
	vector<string> out;
	vector<Item*> items = GetItems();
	for (size_t i = 0; i < items.size(); i++) {
		out.push_back(items[i]->name);
	}
	return out;
}


void Creature::UpdateArmor(int value) {
	ac = ac + value;
}


