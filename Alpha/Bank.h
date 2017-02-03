#include <iostream>
#include <vector>

#include "Item.h"

class Player;

#ifndef BANK_H
#define BANK_H

class Bank
{
public:
	Bank();

	Bank(Player*);

	~Bank();

private:
	std::vector<Item*> item;
	Player* player;

public:
	void deposit(Item*);
	void deposit(int);
	void deposit(int, int);

	void withdraw(int);
	void withdraw(int, int);

	void displayBank();

	void save();
	void load();
};

#endif