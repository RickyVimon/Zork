#include "pch.h"
#include "World.h"
#include "Room.h"
#include "Exit.h"


World::World()
{
	//Creating all the rooms in the map:

	Room* entrance = new Room("Entrance", "This is the training area, where your adventure starts, you can practice fighting against some dummies to get in shape for tha adventures you will face later on. You can see some fighting dummies and a closed door behind them. \n");
	Room* coutyard = new Room("Coutyard", "You are in the coutyard of the castle, in the central part of it you can see a some dead bodies with the colours of the guards around. There is a big door in the north direction, at the end of the stairs, there is also two other small doors, at each other sides of the courtyard. \n");

	Exit* entrance_door = new Exit("Entrance door", "Una puerta de madera con clavos de metal", entrance, coutyard);

	entities.push_back(entrance);
	entities.push_back(coutyard);
	entities.push_back(entrance_door);
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
