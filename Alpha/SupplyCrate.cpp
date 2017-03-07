#include "SupplyCrate.h"


SupplyCrate::SupplyCrate()
{
	loot = { 
		new DropDefinition(3, 50, 13, 148), //Oak logs
		new DropDefinition(5, 50, 16, 59), //Willow logs
		new DropDefinition(7, 50, 10, 48), //Maple logs
		new DropDefinition(9, 25, 20, 49), //Yew logs
		new DropDefinition(11, 25, 10, 20), //Magic logs
		new DropDefinition(225, 25, 3, 12), //Iron ore
		new DropDefinition(227, 25, 3, 15), //Coal ore
		new DropDefinition(229, 25, 3, 70), //Gold ore
		new DropDefinition(231, 25, 2, 7), //Mithril ore
		new DropDefinition(233, 10, 5, 15), //Adamant Ore
		new DropDefinition(235, 10, 1, 2), //Rune Ore
		new DropDefinition(845, 50, 1, 5), //Sapphire
		new DropDefinition(847, 50, 1, 5), //Emerald
		new DropDefinition(849, 50, 1, 5), //Ruby
		new DropDefinition(851, 50, 1, 5), //Diamond
		new DropDefinition(596, 50, 3, 6), //Guam leaf
		new DropDefinition(598, 50, 3, 6), //Tarromin
		new DropDefinition(600, 50, 2, 5), //Ranarr
		new DropDefinition(602, 50, 2, 3), //Harralander
		new DropDefinition(604, 50, 2, 3), //Irit
		new DropDefinition(606, 50, 1, 3), //Kwuarm
		new DropDefinition(578, 35, 10, 30), //Limpwurt root
		new DropDefinition(580, 35, 10, 30), //White berries
		new DropDefinition(138, 50, 5, 12), //Raw anchovies
		new DropDefinition(142, 50, 5, 12), //Raw trout
		new DropDefinition(148, 50, 5, 12), //Raw salmon
		new DropDefinition(152, 50, 5, 11), //Raw lobster
		new DropDefinition(150, 50, 5, 12), //Raw tuna
		new DropDefinition(156, 20, 5, 21), //Raw swordfish
		new DropDefinition(160, 20, 5, 21), //Raw shark
		new DropDefinition(516, 50, 2143, 9048), //Coins
		new DropDefinition(219, 20, 30, 391), //Rune essence
		new DropDefinition(451, 20, 5, 31), //Leather
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