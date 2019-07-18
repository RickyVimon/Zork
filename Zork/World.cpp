#include "pch.h"
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include "Universal.h"
#include<boost/tokenizer.hpp>


World::World()
{
	game_completed = false;
	game_over = false;

	default_commands = { "look","move","attack","use","equip","unequip", "take", "drop","stats","help", "north", "south", "east", "west" };
	directions = { "north", "south", "east", "west" };
	//intro:----------------------------------------------------------------------------------------------------------------------------
	std::ifstream f("title.txt");

	if (f.is_open())
		std::cout << f.rdbuf();

	//Creating all the rooms in the map:------------------------------------------------------------------------------------------------
	Room* entrance = new Room("Entrance", "\nThis is the training area, where your adventure starts, you can practice fighting against some dummies to get in shape for tha adventures you will face later on. You can see some fighting dummies and a closed door behind them. \n");
	Room* coutyard = new Room("Coutyard", "\nYou are in the coutyard of the castle, in the central part of it you can see a some dead bodies with the colours of the guards around. There is a big door in the north direction, at the end of the stairs, there is also two other small doors, at each other sides of the courtyard. \n");
	Room* armory = new Room("Armory", "\nYou are in the armory of the castle, there are some weapons around like a sword, a round shield, a dane axe, and a spear.\n");
	Room* barracks = new Room("Barracks", "\nThis is the barracks of the castle, where all the soldiers sleep, there is no one here but you can see a chest.\n");
	Room* garden = new Room("Garden", "\nThe gardens of the royality have been the jewel of the crown, with flowers from all the colours of the rainbow. There is a wanter fountain in the middle of the garden and a huge door on the north.\n");
	Room* hall = new Room("Hall", "\nThis is the hall of the castle, you can see the King's Throne shinig at the end of the saloon.\n");

	entities.push_back(entrance);
	entities.push_back(coutyard);
	entities.push_back(armory);
	entities.push_back(barracks);
	entities.push_back(garden);
	entities.push_back(hall);

	Exit* entrance_door = new Exit("North", "South", "Entrance door", "", entrance, coutyard);
	Exit* east_corridor = new Exit("East", "West", "Armory corridor", "", coutyard, armory);
	Exit* west_corrifor = new Exit("West", "East", "Barracks corridor", "", coutyard, barracks);
	Exit* stairs = new Exit("North", "South", "Garden stairs", "", coutyard, garden);
	Exit* hall_door = new Exit("North", "South", "Hall's Door", "", garden, hall);

	entities.push_back(entrance_door);
	entities.push_back(east_corridor);
	entities.push_back(west_corrifor);
	entities.push_back(stairs);
	entities.push_back(hall_door);
	


	//Creating Enemies:--------------------------------------------------------------------------------------------------------------
	Enemy* dummy = new Enemy("Dummy", "A wooden training target, you can try to attack it.\n", coutyard);
	Enemy* thief = new Enemy("Thief", "A thief if trying to scape from the authorities! Attack him before he attacks you!\n", hall);

	entities.push_back(dummy);
	entities.push_back(thief);

	//Creating all Items:--------------------------------------------------------------------------------------------------------------	

	Item* chest = new Item("Chest", "Captain's chest", barracks, 0, COMMON);
	Item* hall_key = new Item("Key", "It has the symbol of the royalty family on the bottom", chest, 0, COMMON);
	Item* sword = new Item("Sword", "A one-handed sword", armory, 10, WEAPON);
	Item* shield = new Item("Shield", "A wooden rounded shape shield", armory, 2, ARMOR);
	Item* helmet = new Item("helmet", "A basic steel helmet, it offer nice protection against headshots.", dummy, 1, ARMOR);
	Item* dagger = new Item("Dagger", "A lethal dagger if it's used by the right hands.", thief, 6, WEAPON);
	Item* stick = new Item("stick", "Just a training wood stick.", dummy, 2, WEAPON);
	Item* chainshirt = new Item("Chainshirt", "An smaller version of a chainmail. It offers a decent amount of protection.", entrance, 2, ARMOR);

	entities.push_back(chest);
	entities.push_back(hall_key);
	entities.push_back(sword);
	entities.push_back(shield);

	//Creating Player:---------------------------------------------------------------------------------------------------------------

	bool char_created = 0;
	char key;
	string input_text;
	string name;
	string char_description = "It's you.";

	cout << "First of all, whats your name?\n";
	cin >> name;

	player = new Player(name, char_description, entrance);
	entrance->container.remove(player);

	cout << "Welcome " << name << "!. In this tutorial, you can choose to become one of the 3 fighters classes.\n";
	cout << "\n- Berserker: These elite warriors can use the most powerful weapon of the game, the dane axes. This class if focused on attack and dealing lots of damage.\n";
	cout << "\n- Slayer: They are masters of the sword and the shield, well balanced class which can deal good damage and algo good deffensive stats.\n";
	cout << "\n- Lancer: Lancer are the first line forces, equiped with a shield and a deadly spear. This class is more focused of defensive but the change of inflicting a critical is higher because of their spears.\n";
	cout << "\n\n So, have you decided? Do you want to become a BERSERKER, a SLAYER or a LANCER?\n";

	while (!char_created)
	{
		key = _getch();
		if (key == '\b') // backspace
		{
			if (input_text.length() > 0)
			{
				input_text.pop_back();
				//cout << BACKSPACE;
				cout << '\b';
				cout << " ";
				cout << '\b';
			}
		}
		else if (key != '\r') // !return
		{
			input_text += key;
			cout << key;
		}
		else //return
		{
			if (Universal::ToLowerString(input_text) == "berserker") {
				player->SetStats(name, BERSERKER);
				Command("look");
				char_created = true;
			}
			else if (Universal::ToLowerString(input_text) == "slayer") {
			player->SetStats(name, SLAYER);
			Command("look");
			char_created = true;
			}
			else if (Universal::ToLowerString(input_text) == "lancer") {
			player->SetStats(name, LANCER);
			Command("look");
			char_created = true;
			}
			else {
			cout << "Sorry, I dont understand you. Do you want to become a BERSERKER, a SLAYER or a LANCER?\n";
			input_text = "";
			}
		}
	}

}


World::~World()
{
}


void World::UserInput() {
	char key;
	while (!game_over && !game_completed) {
		key = _getch();
		if (key == '\b') // backspace
		{
			if (input_text.length() > 0)
			{
				input_text.pop_back();
				//cout << BACKSPACE;
				cout << '\b';
				cout << " ";
				cout << '\b';
			}
		}
		else if (key != '\r') // !return
		{
			input_text += key;
			cout << key;
		}
		else { //return
			Command(input_text);
			input_text.clear();
		}
	}

}

void World::Command(string input) {
	string direction = "";
	string action;

	if (ParseCommand(input, default_commands) == "") {
		cout << "\nSorry I didn't understand you, what do you want to do?\n";
		input_text.clear();
		UserInput();
	}
	else
		action = ParseCommand(input, default_commands);

	//Actions which can be understood with one argument:------------------------------------------------

	if (action == "look") {
		//check if it is a Look or a Look + args
		if (input != "look") {
			vector<Item*> items = player->GetRoom()->GetItems();
			vector<Enemy*> enemies = player->GetRoom()->GetEnemies();
			vector<string> enemy_names = player->GetRoom()->GetEnemiesNames();
			vector<string> item_names = player->GetRoom()->GetItemsNames();
			string itemname = ParseCommand(input, item_names);
			for (size_t j = 0; j < items.size(); j++) {
				if (Universal::ToLowerString(items[j]->name) == itemname)
					cout << "\nYou take a closer look to the " << items[j]->name << ". " << items[j]->description << ".\n";
			}
			string enemyname = ParseCommand(input, enemy_names);
			for (size_t j = 0; j < enemies.size(); j++) {
				if (Universal::ToLowerString(enemies[j]->name) == enemyname)
					cout << "\nYou take a careful look to the  enemy " << enemies[j]->name << ". " << enemies[j]->description << ".\n";
			}
		}
		else {
			player->GetRoom()->Look();
			input_text = "";
		}
	}
	else if (action == "north" || action == "south" || action == "west" || action == "east") {
		Move(action);
		player->GetRoom()->Look();
		input_text = "";
	}
	else if (action == "move") {
		direction = ParseCommand(input, directions);
		Move(direction);
		player->GetRoom()->Look();
		input_text = "";
	}
	else if (action == "stats") {
		player->PrintStats();
	}
	else if (action == "help") {

	}
	else if (action == "take") {
		//check if it is a Look or a Look + args
		if (input != "take") {
			vector<string> item_names = player->GetRoom()->GetItemsNames();
			string itemname = ParseCommand(input, item_names);
			if (itemname != "") {
				Item* item = player->GetRoom()->GetItems(itemname);
				if (item != NULL) {
					if (item->type == ITEM) {
						player->Take(item);
						player->GetRoom()->container.erase(std::remove(player->GetRoom()->container.begin(), player->GetRoom()->container.end(), (Entity*)item), player->GetRoom()->container.end());
						return;
					}
					else
						cout << "\nYou cannot take that!.\n";
				}
				else {
					cout << "\nYou forgot to write what do you want to take.\n";
					input_text = "";
				}
			}
			else
				cout << "\nThere is no " << input << " you can take.\n";
		}
	}
	else if (action == "drop") {
		//check if it is a Look or a Look + args
		if (input != "drop") {
			vector<string> item_names = player->GetItemsNames();
			string itemname = ParseCommand(input, item_names);
			Item* item = player->GetItems(itemname);
			if (item != NULL)
				player->Drop(item);
			else
				cout << "\nYou can't drop an item which you don't have.\n";
		}
		else {
			cout << "\nYou forgot to write what do you want to Drop.\n";
			input_text = "";
		}
	}
	else if (action == "equip") {
		if (input != "equip") {
			vector<string> item_names = player->GetItemsNames();
			string itemname = ParseCommand(input, item_names);
			if (itemname != "") {
				player->Equip(itemname);
				cout << "\n" << player->GetItems(itemname)->name << " equiped.\n";
			}
			else
			{
				cout << "I don't really know what is that, it's looks like you want to equip something but you haven't used the right command.\n";
			}
		}else 
			cout << "\nYou forgot to write what do you want to Equip.\n";
	}
	else if (action == "unequip") {
		if (input != "unequip") {
			vector<string> item_names = player->GetItemsNames();
			string itemname = ParseCommand(input, item_names);
			if (itemname != "") {
				player->Unequip(itemname);
				cout << "\n" << player->GetItems(itemname)->name << " unequiped.\n";
			}
			else
			{
				cout << "\nI don't really know what is that, it's looks like you want to equip something but you haven't used the right command.\n";
			}
		}
		else
			cout << "\nYou forgot to write what do you want to Equip.\n";
	}

	else if (action == "attack") {		
		game_completed = player->Attack();
	}
}

void World::Move(string direction)
{
	if (direction != "")
		player->LeaveRoom(direction);
}


string World::ParseCommand(string input, vector<string> options)
{
	string out = "";
	boost::tokenizer<> tok(input);
	vector<string> minus;
	for (size_t j = 0; j < options.size(); j++) {
		minus.push_back(Universal::ToLowerString(options[j]));
	}
	for (boost::tokenizer<>::iterator command_word = tok.begin(); command_word != tok.end();++command_word) {
		if (std::find(minus.begin(), minus.end(), Universal::ToLowerString(*command_word)) != minus.end()) {
			out =  Universal::ToLowerString(*command_word);
			return out;
		}
	}
	return out;
}
