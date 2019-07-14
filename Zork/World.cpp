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


World::World()
{
	//Creating all the rooms in the map:------------------------------------------------------------------------------------------------

	Room* entrance = new Room("Entrance", "\nThis is the training area, where your adventure starts, you can practice fighting against some dummies to get in shape for tha adventures you will face later on. You can see some fighting dummies and a closed door behind them. \n");
	Room* coutyard = new Room("Coutyard", "\nYou are in the coutyard of the castle, in the central part of it you can see a some dead bodies with the colours of the guards around. There is a big door in the north direction, at the end of the stairs, there is also two other small doors, at each other sides of the courtyard. \n");
	Room* armory = new Room("Armory", "\nYou are in the armory of the castle, there are some weapons around like a sword, a round shield, a dane axe, and a spear.\n");
	Room* barracks = new Room("Barracks", "\nThis is the barracks of the castle, where all the soldiers sleep, there is no one here but you can see a chest.\n");
	Room* garden = new Room("Royal Garden", "\nThe gardens of the royality have been the jewel of the crown, with flowers from all the colours of the rainbow. There is a wanter fountain in the middle of the garden and a huge door on the north.\n");
	Room* hall = new Room("King's Hall", "\nThis is the hall of the castle, you can see the King's Throne shinig at the end of the saloon.\n");

	entities.push_back(entrance);
	entities.push_back(coutyard);
	entities.push_back(armory);
	entities.push_back(barracks);
	entities.push_back(garden);
	entities.push_back(hall);

	Exit* entrance_door = new Exit("North", "South", "Entrance door", "", entrance, coutyard);
	Exit* east_corridor = new Exit("East","West", "Armory corridor", "", coutyard, armory);
	Exit* west_corrifor = new Exit("West","East", "Barracks corridor", "", coutyard, barracks);
	Exit* stairs = new Exit("North", "South", "Garden stairs", "", coutyard, garden);
	Exit* hall_door = new Exit("North", "South", "Hall's Door", "", garden, hall);

	entities.push_back(entrance_door);
	entities.push_back(east_corridor);
	entities.push_back(west_corrifor);
	entities.push_back(stairs);
	entities.push_back(hall_door);


	//Creating all Items:--------------------------------------------------------------------------------------------------------------
	
	Item* chest = new Item("Chest", "Captain's chest", barracks);
	Item* hall_key = new Item("Hall's Key","It has the symbol of the royalty family on the bottom", chest);
	Item* sword = new Item("Sword", "A one-handed sword", armory);
	Item* shield = new Item("Shield", "A wooden rounded shape shield", armory);
	Item* dane_axe = new Item("Dane Axe", "A great axe with a long wooden shaft of around 1,5 meters", armory);
	Item* spear = new Item("Spear", "A piercing spear of around 2m long", armory);

	//Creating Enemies:--------------------------------------------------------------------------------------------------------------

	Enemy* dummy = new Enemy("Dummy", "A wooden training target, you can try to attack it.\n", entrance);
	Enemy* thief = new Enemy("Thief", "A thief if trying to scape from the authorities! Attack him before he attacks you!\n", hall);


	//Creating Player:---------------------------------------------------------------------------------------------------------------
	
	bool char_created = 0;
	char key;
	string input_text;
	string name;
	string char_description = "It's you.";

	cout << "First of all, whats your name?\n";
	cin >> name;
	Player* player = new Player(name, char_description , entrance);
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
		else { //return
			const char* c = input_text.c_str();
		
			if (input_text == "BERSERKER" || input_text == "Berserker" || input_text == "berserker") {
				player->SetStats(name, BERSERKER);
				char_created = true;
			}
			else if (input_text == "SLAYER" || input_text == "Slayer" || input_text == "slayer") {
				player->SetStats(name, SLAYER);
				char_created = true;
			}
			else if (input_text == "LANCER" || input_text == "Lancer" || input_text == "lancer") {
				player->SetStats(name, LANCER);
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

bool World::ParseCommand()
{
	bool correct_parse = true;

	//TODO all the parsing

	return correct_parse;
}

