#include "Item.h"
#include "Skills.h"
#include "Inventory.h"

class Player;

#ifndef FOOD_H
#define FOOD_H

class Food
{
public:
	Food();

	Food(Player*);

	~Food();

private:
	Player *player;

public:
	void eat(int);
};

#endif