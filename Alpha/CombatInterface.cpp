#include "CombatInterface.h"
#include <iostream>
#include <vector>
#include "Skills.h"


CombatInterface::CombatInterface()
{
}


CombatInterface::~CombatInterface()
{
}


void CombatInterface::barDisplay(int cur, int max)
{
	double ratio = (double)cur / max;
	int fill = 30 * ratio;

	if (cur)
		fill ? fill : fill = 1;

	std::cout << "     [";

	for (int i = 0; i < fill; i++)
		std::cout << ":";
	for (int i = 0; i < 30 - fill; i++)
		std::cout << " ";

	std::cout << "]";
}

void CombatInterface::npcDisplay(Npc *npc)
{
	std::cout << "\t(Level " << npc->getNpcDefinition()->getLevel() << ") " << npc->getNpcDefinition()->getName() << std::endl;
	std::cout << "   HP: " << npc->getHitpoints() << " / " << npc->getNpcDefinition()->getHitpoints() << "   " << std::endl;
	barDisplay(npc->getHitpoints(), npc->getNpcDefinition()->getHitpoints());
	std::cout << "   " << std::endl;
}

void CombatInterface::playerDisplay(Player *player)
{
	std::cout << std::endl << " > " << std::endl << std::endl;
	std::cout << "\t(Level " << player->skills->getCombatLevel() << ") " << player->getName() << std::endl;
	std::cout << "   HP: " << player->skills->getEffect(hitpoints) << " / " << player->skills->getLevel(hitpoints) << "\t\tPray: " << player->skills->getEffect(prayer) << " / " << player->skills->getLevel(prayer) << "   " << std::endl;
	barDisplay(player->skills->getEffect(hitpoints), player->skills->getLevel(hitpoints));
	std::cout << "   " << std::endl;
	std::cout << std::endl << " > " << std::endl << std::endl;
}

void CombatInterface::attackDisplay(Player* player)
{
	std::vector<std::string> names;
	int j = 0;

	switch (player->getAttackStyle())
	{
	case 0:
		names.push_back("Accurate");
		names.push_back("Aggressive");
		names.push_back("Defensive");
		names.push_back("Controlled");
		break;
	case 1:
		j += 4;
		names.push_back("Rapid");
		names.push_back("Longrange");
		break;
	case 2:
		j += 6;
		names.push_back("Cast Spell");
		break;
	default:
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		j++;
		if (i < names.size())
			std::cout << " [" << i + 1 << "] " << names[i];
		if (j == player->getCombatStance())
			std::cout << " <-";
		std::cout << std::endl;
		if (i != 3) std::cout << std::endl;
	}
}

void CombatInterface::displayMenu(Player* player, Npc* npc)
{
	std::cout << "\t\t\t\t---Combat---" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl << std::endl;
	npcDisplay(npc);
	playerDisplay(player);
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << " [1] Attack" << std::endl;
	std::cout << " [2] Stats" << std::endl;
	std::cout << " [3] Inventory" << std::endl;
	std::cout << " [4] Equipment" << std::endl;
	std::cout << " [5] Prayer" << std::endl;
	std::cout << " [6] Magic" << std::endl;
	std::cout << " [7] Escape" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";
}

void CombatInterface::displayScreen(Player* player, Npc* npc)
{
	std::cout << "\t\t\t\t---Combat---" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl << std::endl;
	npcDisplay(npc);
	playerDisplay(player);
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	attackDisplay(player);
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";
}