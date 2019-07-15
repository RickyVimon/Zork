#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Exit.h"
#include "Universal.h"

enum Hero_Class {
	BERSERKER,
	SLAYER,
	LANCER
};

class Player : public Creature
{
public:
	Player(string name, string description, Room* room);
	~Player();
	void SetStats(string name, Hero_Class role);
	void PrintStats();
	void ChangeRoom(Exit* exit);
	Room* GetRoom();
	string GetRoomName();
	bool LeaveRoom(string direction, vector<Exit*>);

private:
	string heroclass;
	Room* actualroom;
};
#endif
