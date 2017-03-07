#include "Barrows.h"
#include "Combat.h"
#include "Inventory.h"

#include <algorithm>


Barrows::Barrows()
{
	brothers[0] = new Npc(122);
	brothers[1] = new Npc(123);
	brothers[2] = new Npc(124);
	brothers[3] = new Npc(125);
	brothers[4] = new Npc(126);
	brothers[5] = new Npc(127);

	loot = {
		new DropDefinition(1016, 1, 1, 1), //Ahrim's set
		new DropDefinition(1018, 1, 1, 1),
		new DropDefinition(1020, 1, 1, 1),
		new DropDefinition(1022, 1, 1, 1),
		new DropDefinition(1024, 1, 1, 1), //Dharok's set
		new DropDefinition(1026, 1, 1, 1),
		new DropDefinition(1028, 1, 1, 1),
		new DropDefinition(1030, 1, 1, 1),
		new DropDefinition(1032, 1, 1, 1), //Guthan's set
		new DropDefinition(1034, 1, 1, 1),
		new DropDefinition(1036, 1, 1, 1),
		new DropDefinition(1038, 1, 1, 1),
		new DropDefinition(1040, 1, 1, 1), //Karil's set
		new DropDefinition(1042, 1, 1, 1),
		new DropDefinition(1044, 1, 1, 1),
		new DropDefinition(1046, 1, 1, 1),
		new DropDefinition(1048, 1, 1, 1), //Torag's set
		new DropDefinition(1050, 1, 1, 1),
		new DropDefinition(1052, 1, 1, 1),
		new DropDefinition(1054, 1, 1, 1),
		new DropDefinition(1056, 1, 1, 1), //Verac's set
		new DropDefinition(1058, 1, 1, 1),
		new DropDefinition(1060, 1, 1, 1),
		new DropDefinition(1062, 1, 1, 1),
		new DropDefinition(540, 200, 1, 2889), //Mind rune
		new DropDefinition(545, 200, 1, 885), //Chaos rune
		new DropDefinition(547, 200, 1, 461), //Death rune
		new DropDefinition(548, 100, 1, 236), //Blood rune
		new DropDefinition(516, 200, 1, 5306), //Coins
		new DropDefinition(813, 50, 1, 1), //Dragon med helm
		new DropDefinition(1064, 200, 1, 191) //Bolt rack
	};
}


Barrows::~Barrows()
{
	for (int i = 0; i < 6; i++)
		delete brothers[i];

	for (auto it = loot.begin(); it != loot.end(); ++it)
		delete *it;
	loot.clear();
}


std::vector<Item*> Barrows::getLoot()
{
	std::vector<Item*> chest;
	std::vector<int> previousLoot;
	bool getLoot;
	int weightSum, randomNum;
	

	for (int i = 0; i < 6; i++)
	{
		getLoot = true;
		weightSum = 0;

		for (int j = 0; j < loot.size(); j++)
			weightSum += loot[j]->getChance();

		randomNum = rand() % weightSum;
		weightSum -= randomNum;

		for (int j = 0; j < loot.size(); j++)
		{
			weightSum -= loot[j]->getChance();
			if (weightSum < 1)
			{
				if (previousLoot.size())
				{
					for (int k = 0; k < previousLoot.size(); k++)
						if (previousLoot[k] == j)
							getLoot = false;
				}

				if (getLoot)
				{
					chest.push_back(new Item(loot[j]->getIndex(), rand() % (loot[j]->getMax() - loot[j]->getMin() + 1) + loot[j]->getMin()));
					previousLoot.push_back(j);
					break;
				}
			}
		}
	}

	return chest;
}

void Barrows::play(Player* player)
{
	std::random_shuffle(std::begin(brothers), std::end(brothers));

	for (int i = 0; i < 6; i++)
	{
		Combat *combat = new Combat;
		combat->battle(player, brothers[i]);
		delete combat;

		if (brothers[i]->getHitpoints())
			return;
	}
	
	std::vector<Item*> drop = getLoot();

	if (drop.size())
	{
		for (auto i : drop)
		{
			if (player->inventory->canAdd(*i))
				player->inventory->add(new Item(i->getId(), i->getAmount()));
		}
	}
}