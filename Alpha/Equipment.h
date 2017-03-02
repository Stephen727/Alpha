#include <iostream>

#include "Item.h"
#include "Skills.h"

class Player;

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment
{
public:
	Equipment();

	Equipment(Player*);

	~Equipment();

private:
	Player *player;
	Item *item[11];

	int bonus[8];

	void calculateBonus();

public:
	bool canEquip(Item*);

	void unequip(int);
	void equip(int);

	bool hasAmmo();
	void useAmmo();

	void clear();
	void clearSlot(int);

	Item* getItem(int);
	int getBonus(int);

	void displayEquip();
	void displayBonus();

	void save();
	void load();
};

#endif