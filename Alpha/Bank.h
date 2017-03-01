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

	void deposit(int);
	void deposit(int, int);

	void withdraw(int);
	void withdraw(int, int);

	void displayBank();

	void makeDeposit();
	void makeWithdraw();

	void swap(int, int);
public:
	void deposit(Item*);
	void access();

	void save();
	void load();
};

#endif