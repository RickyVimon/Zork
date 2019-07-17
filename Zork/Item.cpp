#include "pch.h"
#include "Item.h"
#include "Room.h"
#include "Universal.h"


Item::Item(string name, string description, Entity* parent, int value, ItemType item_type) :
	Entity(name, description, parent), value_mod(value), item_type(item_type)
{
	type = ITEM;
	switch (item_type) {
	case(ARMOR):
		stat_name_mod = "Armor";
		break;
	case (WEAPON):
		damage = value_mod;
		break;
	default:
		break;
	}
}


Item::~Item()
{
}


vector<Item*> Item::GetItems() {
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

void Item::ChangeStat(int value) {
	int val = value;
	Creature* crt = (Creature*)parent;
	switch (this->item_type) {
	case(ARMOR):
		crt->UpdateArmor(val);
		break;
	}
}

void Item::EquipItem() {
	ChangeStat(value_mod);
}

void Item::Unnequip() {
	ChangeStat ((-1) * value_mod);
}



