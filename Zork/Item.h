#pragma once
#include "Entity.h"
#include <string>

enum ItemType
{
	COMMON,
	WEAPON,
	ARMOR,
	USABLE
};

class Item :
	public Entity
{
public:
	Item(string name, string description, Entity* parent, int value, ItemType item_type);
	~Item();
	void ChangeStat(int value);
	void EquipItem();
	void UnequipItem();
	int damage;
	ItemType item_type;

private:
	vector<Item*> GetItems();
	int armor;
	string stat_name_mod;
	int value_mod;
};

