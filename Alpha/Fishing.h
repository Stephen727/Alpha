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

	void smallNetBait();
	void lureBait();
	void cageHarpoon();
	void bigNetHarpoon();
	void harpoonSmallNet();

	void wait(int);
	bool getInput(char*);
public:
	void fish(int);
};

#endif