#include "Item.h"

class Player;

#ifndef USEITEM_H
#define USEITEM_H

class UseItem
{
public:
	UseItem();

	UseItem(Player*);

	~UseItem();

private:
	Player *player;

	bool isBone(Item*);
	bool isPotion(Item*);
	bool isFood(Item*);
	bool isEquipment(Item*);

public:
	void use(int);
	void select(int);
};

#endif