#pragma once

#include <list>
#include <vector>
#include "Entity.h"
#include "Room.h"
#include "Enemy.h"
#include "Item.h"
#include "Exit.h"
#include <string>

class Player;
class Entity;

class World
{
public:
	World();
	~World();
	Player* player;
	string ParseCommand(string input, vector<string> options);
	void Command(string input);
	void UserInput();
	void Move(string direction);
	bool game_over;
	bool game_completed;

private:
	vector<Entity*> entities;
	vector<string> default_commands;
	vector<string> directions;
	vector<string> command_vector;
	vector<Room*> rooms;
	vector<Enemy*> enemies;
	vector<Exit*> exits;
	vector<Item*> items;
	string input_text;
};