#include <iostream>

#include "Item.h"

class Player;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
public:
	Inventory();

	Inventory(Player*);

	~Inventory();

private:
	Player *player;
	Item *item[20];

public:
	bool canAdd(Item);
	void add(Item*);

	void remove(int);
	void remove(int, int);
	void remove(std::vector<Item>);

	void replace(Item*, int);

	void clear();

	Item* getSlot(int);
	int getFreeSlots();

	bool hasItem(int);
	bool hasItem(int, int);
	bool hasItems(std::vector<Item>);

	int hasAmount(int);

	void removeItem(int);
	void removeItem(int, int);

	void swap(int, int);

	void displayInv();

	void save();
	void load();
};

#endif