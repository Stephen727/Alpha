#include "Loot.h"

#include <random>
#include <ctime>

std::default_random_engine gen((unsigned)time(NULL));
std::uniform_int_distribution<int> roll(0, 99);

Loot::Loot()
{
}


Loot::Loot(int id)
{
	for (int i = 0; i < definitionLoader.lootDefinition.size(); i++)
	{
		if (definitionLoader.lootDefinition[i]->getIndex() == id)
			lootTable = definitionLoader.lootDefinition[i]->getLootTable();
	}
}


Loot::~Loot()
{
}


std::vector<Item*> Loot::getDrop()
{
	std::vector<Item*> drop, temp;
	int dropRoll = roll(gen);

	for (int i = 0; i < lootTable.size(); i++)
	{
		if (lootTable[i]->getChance() == 100)
			drop.push_back(new Item(lootTable[i]->getIndex(), rand() % (lootTable[i]->getMax() - lootTable[i]->getMin() + 1) + lootTable[i]->getMin()));
		else if (lootTable[i]->getChance() > dropRoll)
			temp.push_back(new Item(lootTable[i]->getIndex(), rand() % (lootTable[i]->getMax() - lootTable[i]->getMin() + 1) + lootTable[i]->getMin()));
	}

	if (temp.size())
		drop.push_back(temp[rand() % temp.size()]);

	for (int i = 0; i < drop.size(); i++)
	{
		if (!drop[i]->getItemDefinition()->isStackable() && drop[i]->getAmount() > 1)
		{
			while (drop[i]->getAmount() > 1)
			{
				drop.push_back(new Item(drop[i]->getId(), 1));
				drop[i]->remove();
			}
		}
	}

	return drop;
}