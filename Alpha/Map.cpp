#include "Map.h"
#include <iostream>
#include <string>
#include "Skills.h"
#include "Slayer.h"


Map::Map()
{
}


Map::Map(Player* _player)
{
	player = _player;
}


Map::~Map()
{
}


void Map::display()
{
	std::string username = player->getName();
	username.resize(20);

	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                  " << username << "                                       |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "| Combat:\t" << player->skills->getCombatLevel() << "\t\t    "; player->skills->displayStat(woodcutting); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(hitpoints); std::cout << "\t\t    "; player->skills->displayStat(fletching); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(attack); std::cout << "\t\t    "; player->skills->displayStat(fishing); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(strength); std::cout << "\t\t    "; player->skills->displayStat(cooking); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(defense); std::cout << "\t\t    "; player->skills->displayStat(mining); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(ranged); std::cout << "\t\t    "; player->skills->displayStat(smithing); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(prayer); std::cout << "\t\t    "; player->skills->displayStat(herblore); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(magic); std::cout << "\t\t    "; player->skills->displayStat(crafting); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "| "; player->skills->displayStat(slayer); std::cout << "\t\t    "; player->skills->displayStat(runecrafting); std::cout << "\t\t\t      |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << " \\                                                                           /" << std::endl;
	std::cout << "\t";	player->slayer->getCurrentSlayerTask();
	std::cout << " /                                                                           \\" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "| [1] Lumbridge                                      | [Q] Shops | [R] Bank   |" << std::endl;
	std::cout << "| [2] Varrock                                        | [W] World | [D] Task   |" << std::endl;
	std::cout << "| [3] Falador                                        | [E] Skill | [F] Slayer |" << std::endl;
	std::cout << "| [4] Seers' Village                                 |-----------|------------|" << std::endl;
	std::cout << "| [5] Ardougne                                       | [G] Gear  | [B] Bag    |" << std::endl;
	std::cout << "| [6] Karamja                                        | [S] Save  | [0] Exit   |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";
}