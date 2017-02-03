#include <vector>

#ifndef LOOTDEFINITION_H
#define LOOTDEFINITION_H

#include "DropDefinition.h"

class LootDefinition
{
public:
	LootDefinition() {}

	LootDefinition(int _index, std::vector<DropDefinition*> _lootTable)
	{
		index = _index;
		lootTable = _lootTable;
	}

	~LootDefinition() {}

private:
	int index;
	std::vector<DropDefinition*> lootTable;

public:
	int getIndex() { return index; }
	std::vector<DropDefinition*> getLootTable() { return lootTable; }
};

#endif