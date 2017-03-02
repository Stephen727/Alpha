#include <vector>

#include "DropDefinition.h"
#include "Item.h"

#ifndef SUPPLYCRATE
#define SUPPLYCRATE

class SupplyCrate
{
public:
	SupplyCrate();

	~SupplyCrate();

private:
	std::vector<DropDefinition*> loot;

	Item* roll();
public:
	std::vector<Item*> open();
};

#endif