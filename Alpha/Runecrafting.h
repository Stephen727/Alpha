#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef RUNECRAFTING_H
#define RUNECRAFTING_H

class Runecrafting
{
public:
	Runecrafting();

	Runecrafting(Player*);

	~Runecrafting();

private:
	Player *player;

public:
	void runecraft(int);
};

#endif