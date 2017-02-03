#include <vector>

#include "Item.h"

#ifndef LOOT_H
#define LOOT_H

class Loot
{
public:
	Loot();

	Loot(int);

	~Loot();

private:
	std::vector<DropDefinition*> lootTable;

public:
	std::vector<Item*> getDrop();
};

#endif