#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef FISHING_H
#define FISHING_H

class Fishing
{
public:
	Fishing();

	Fishing(Player*);

	~Fishing();

private:
	Player *player;

	int smallNetBait();
	int lureBait();
	int cageHarpoon();
	int bigNetHarpoon();
	int harpoonSmallNet();

	void wait(int);
	bool getInput(char*);
public:
	void fish(int);
};

#endif