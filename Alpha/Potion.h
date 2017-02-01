#include "Item.h"
#include "Skills.h"
#include "Inventory.h"

class Player;

#ifndef POTION_H
#define POTION_H

class Potion
{
public:
	Potion();

	Potion(Player*);

	~Potion();

private:
	Player *player;

public:
	void drink(int);

};

#endif