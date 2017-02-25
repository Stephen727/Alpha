#include <iostream>
#include <vector>

#include "Player.h"
#include "Item.h"

#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
	Ground();

	Ground(Player*);

	~Ground();

private:
	std::vector<Item*> item;
	Player* player;

public:
	void drop(Item*);
	void display();
	void pickup(int);
};

#endif