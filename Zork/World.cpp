#include "pch.h"
#include "World.h"
#include "Room.h"
#include "Exit.h"


World::World()
{

	//Creating all the rooms in the map:

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
