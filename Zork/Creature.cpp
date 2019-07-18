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
	vector<string> allitems = GetItemsNames();
	for (size_t h = 0; h < allitems.size(); h++) {
		Equip(allitems[h]);
	}
}
void Creature::Drop(Item* item) {
	item->parent = (Entity*)actualroom;
	actualroom->container.push_back(item);
	container.erase(std::remove(container.begin(), container.end(), (Entity*)item), container.end());
	cout << "\n" << item->name << " dropped.\n";
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
void Creature::Unequip(string itemname) {
	Item* item = GetItems(itemname);
	if (item != NULL) {
		if (IsEquipped(itemname)) {
			item->UnequipItem();
			equiped.erase(std::remove(equiped.begin(), equiped.end(), (Entity*)item), equiped.end());
		}
		else
			cout << item->name << " is not equiped.\n";
	}
	else
	{
		cout << "You can't unequip an item you don't have it.\n";
	}
}

bool Creature::IsEquipped(string itemname) {
	for (std::list<Item*>::iterator it = equiped.begin(); it != equiped.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (Universal::ToLowerString(ent->name) == Universal::ToLowerString(itemname)) {
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
		if (ent->type == ITEM) {
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

Item* Creature::GetWeapon() {
	Item* out = NULL;
	vector<Item*> items = GetItems();
	for (size_t i = 0; i < items.size();i++) {
		if (items[i]->item_type == WEAPON) {
			out = items[i];
			return out;
		}
	}
	return out;
}

bool Creature::Attack() {
	//check if you have a weapon equiped
	Item* weapon = GetWeapon();
	if (weapon != NULL) {
		if (IsEquipped(weapon->name)) {
			//doAttack
			vector<Enemy*> enemies = actualroom->GetEnemies();
			if (enemies.size() > 1) {
				cout << "\nThere are no enemies in this room.\n";
			}
			if (enemies.size() == 1) {
				int enemies_ac = enemies[0]->ac;
				if ((Roll(20) + str_mod) >= enemies_ac) {
					cout << "\nYou hit on the target.\n";
					//Roll damage:
					int dmg = Roll(weapon->damage + +str_mod);
					enemies[0]->health = enemies[0]->health - dmg;
					cout << "You have dealt " << dmg << " to the " << enemies[0]->name << ".\n";
				}
				else
				{
					cout << "\nYou missed the attack.\n";
				}
				if (enemies[0]->health <= 0) {
					//enemy dead
					cout << "\nYou killed the " << enemies[0]->name;
					//enemies drops all the weapons
					vector<Item*> enemyloot = enemies[0]->GetItems();
					for (size_t k = 0;  k < enemyloot.size(); k++) {
						enemies[0]->Drop(enemyloot[k]);
					}
					GainExp(enemies[0]->exp);
					actualroom->RemoveEnemy(enemies[0]->name);
					if (Universal::ToLowerString(enemies[0]->name) == "thief") {
						cout << "\n\n\n ::::::::::::::::::::CONGRATULATIONS! YOU KILLED THE THIEF!!!:::::::::::::::::::::::::";
						return true;
					}
					else
					{
						return false;
					}
					
				}
				else {//enemy is alife and he attacks back
					if ((Roll(20) + enemies[0]->str_mod) >= ac) {
						cout << enemies[0]->name << " hit on the target.\n";
						//Roll damage:
						Item* enemyweapon = enemies[0]->GetWeapon();
						int enemydmg = Roll(enemyweapon->damage + enemies[0]->str_mod);
						health = health - enemydmg;
						cout << "You suffer " << enemydmg << "damage by an attack of " << enemies[0]->name << ".\n";
						if (health <= 0) {
							cout << "\n\n\n\n::::::::::::::::You Died:::::::::::::::::::\n\n\n";
							return true;
						}

					}
					else {
						cout << enemies[0]->name << " missed the attack.\n";
					}
				}
				
			}else
				cout << "\nThere is more than one enemy, you need to specify wich one do you want to attack.\n";
		}
		else {
			cout << "\nYou need to equip a weapon first.\n";
		}
	}		
	else
		cout << "\nYou don't have any equipped weapon to atttack with.\n";
	return false;
}

/*bool Creature::Attack(string enemyname) {
	//check if you have a weapon equiped
	Item* weapon = GetWeapon();
	if (weapon != NULL) {
		Enemy* target = NULL;
		vector<Enemy*> enemies = actualroom->GetEnemies();
		for (size_t i = 0; i < enemies.size();i++) {
			if (Universal::ToLowerString(enemies[i]->name) == Universal::ToLowerString(enemyname)) {
				target = enemies[i];
			}
		}
		if (IsEquipped(weapon->name)) {
			//doAttack
			if (Roll(20) >= target->ac) {
				cout << "\nYou hit on the target.\n";
				//Roll damage:
				int dmg = Roll(weapon->damage);
				target->health = target->health - dmg;
				cout << "\nYou have dealt " << dmg << " to the " << target->name << ".\n";
				if (target->health <= 0) {
					//enemy dead
					cout << "\nYou killed the " << target->name;
					//enemies drops all the weapons
					vector<Item*> enemyloot = target->GetItems();
					for (size_t j = 0; enemyloot.size() < j; j++) {
						target->Drop(enemyloot[j]);
					}
					GainExp(target->exp);
				}
				else {//enemy is alife and he attacks back
					if (Roll(20) >= ac) {
						cout << "\n" << target->name << " hit on the target.\n";
						//Roll damage:
						Item* enemyweapon = target->GetWeapon();
						int enemydmg = Roll(enemyweapon->damage);
						health = health - enemydmg;
						cout << "\nYou suffer " << enemydmg << "damage by an attack of " << target->name << ".\n";
						if (health <= 0) {
							cout << "\n\n\n\nYou Died\n\n\n";
						}

					}
				}
			}
		}
	}
	else
	{
		cout << "\nYou don't have any equipped weapon to atttack with.\n";
	}
	
	return false;
}*/

void Creature::GainExp(int gainexp) {
	exp = exp + gainexp;
	if (exp >= lvl * 10) {
		lvl++;
		max_health = con * lvl;
		health = max_health;
		cout << "\n\n You advanced to Level " << lvl << ".\n\n";
	}
}

bool Creature::IsAlive() {
	if (health <= 0) {
		return false;
	}
	else
		return true;
}

