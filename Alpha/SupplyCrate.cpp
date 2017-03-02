#include "SupplyCrate.h"


SupplyCrate::SupplyCrate()
{
	loot = { 
		new DropDefinition(3, 25, 13, 148), //Oak logs
		new DropDefinition(5, 25, 16, 59), //Willow logs
		new DropDefinition(7, 25, 10, 48), //Maple logs
		new DropDefinition(9, 10, 20, 49), //Yew logs
		new DropDefinition(11, 10, 10, 20), //Magic logs
		new DropDefinition(225, 10, 3, 12), //Iron ore
		new DropDefinition(227, 10, 3, 15), //Coal ore
		new DropDefinition(229, 10, 3, 70), //Gold ore
		new DropDefinition(231, 10, 2, 7), //Mithril ore
		new DropDefinition(233, 5, 5, 15), //Adamant Ore
		new DropDefinition(235, 5, 1, 2), //Rune Ore
		new DropDefinition(845, 25, 1, 5), //Sapphire
		new DropDefinition(847, 25, 1, 5), //Emerald
		new DropDefinition(849, 25, 1, 5), //Ruby
		new DropDefinition(851, 25, 1, 5), //Diamond
		new DropDefinition(596, 25, 3, 6), //Guam leaf
		new DropDefinition(598, 25, 3, 6), //Tarromin
		new DropDefinition(600, 25, 2, 5), //Ranarr
		new DropDefinition(602, 25, 2, 3), //Harralander
		new DropDefinition(604, 25, 2, 3), //Irit
		new DropDefinition(606, 25, 1, 3), //Kwuarm
		new DropDefinition(138, 25, 5, 12), //Raw anchovies
		new DropDefinition(142, 25, 5, 12), //Raw trout
		new DropDefinition(148, 25, 5, 12), //Raw salmon
		new DropDefinition(152, 25, 5, 11), //Raw lobster
		new DropDefinition(150, 25, 5, 12), //Raw tuna
		new DropDefinition(156, 10, 5, 21), //Raw swordfish
		new DropDefinition(160, 10, 5, 21), //Raw shark
		new DropDefinition(516, 25, 2143, 9048), //Coins
		new DropDefinition(219, 10, 30, 391), //Rune essence
		new DropDefinition(451, 10, 5, 31), //Leather
		new DropDefinition(26, 1, 1, 1), //Dragon hatchet
		new DropDefinition(250, 1, 1, 1) //Dragon pickaxe
	};
}

SupplyCrate::~SupplyCrate()
{
	for (auto it = loot.begin(); it != loot.end(); ++it)
		delete *it;
	loot.clear();
}


Item* SupplyCrate::roll()
{
	int weightSum = 0;

	for (int i = 0; i < loot.size(); i++)
		weightSum += loot[i]->getChance();

	int randomNum = rand() % weightSum;
	weightSum -= randomNum;

	for (int i = 0; i < loot.size(); i++)
	{
		weightSum -= loot[i]->getChance();
		if (weightSum < 1)
			return new Item(loot[i]->getIndex(), rand() % (loot[i]->getMax() - loot[i]->getMin() + 1) + loot[i]->getMin());
	}
}

std::vector<Item*> SupplyCrate::open()
{
	int rollNum = rand() % 1 + 2;
	std::vector<Item*> crateLoot;


	for (int i = 0; i < rollNum; i++)
		crateLoot.push_back(roll());

	return crateLoot;
}