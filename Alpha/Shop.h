#include "DefinitionLoader.h"
#include "Player.h"
#include "Inventory.h"

#ifndef SHOP_H
#define SHOP_H

class Shop
{
public:
	Shop();

	Shop(int);

	~Shop();

private:
	std::string name;
	std::vector<Item> stock;

	void display(const Player&);
	bool canPurchase(const Player&, int);
public:
	void enter(Player*);
};

#endif