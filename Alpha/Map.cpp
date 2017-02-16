#include "Map.h"
#include <iostream>
#include <string>
#include <conio.h>

#include "Inventory.h"
#include "Bank.h"
#include "Equipment.h"
#include "Skills.h"
#include "Slayer.h"
#include "UseItem.h"
#include "Shop.h"


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


void Map::shopDisplay()
{
	int input;

	system("CLS");
	std::cout << "   ---Shops---" << std::endl;
	for (int i = 0; i < definitionLoader.shopDefinition.size(); i++)
		std::cout << " [" << i + 1 << "] " << definitionLoader.shopDefinition[i]->getName() << std::endl;
	std::cout << std::endl << ">";

	while (!(std::cin >> input) || (input < 0 || input > definitionLoader.shopDefinition.size()))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	if (input)
	{
		Shop *shop = new Shop(input - 1);
		shop->enter(player);
		delete shop;
	}
}

bool Map::getInput()
{
	char select = ' ';
	int input;
	select = _getch();
	select = toupper(select);

	switch (select)
	{
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case 'Q': //Shops
		shopDisplay();
		break;
	case 'W': //World
		break;
	case 'E': //Skill
		break;
	case 'R': //Bank
		player->bank->access();
		break;
	case 'D': //Task
		break;
	case 'F': //Slayer
		break;
	case 'G': //Equipment
		do
		{
			player->equipment->displayEquip();
			while (!(std::cin >> input))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}
			player->equipment->unequip(input - 1);
		} while (input);
		break;
	case 'B': //Inventory
		do
		{
			player->inventory->displayInv();
			while (!(std::cin >> input))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}
			if (input)
				player->useItem->select(input - 1);
		} while (input);
		break;
	case 'S': //Save
		player->save();
		break;
	case '0': //Exit
		return false;
		break;
	default:
		getInput();
		break;
	}

	return true;
}

void Map::display()
{
	std::string username = player->getName();
	username.resize(20);

	do
	{
		system("CLS");
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
		std::cout << "| [1] Lumbridge                                   | [Q] Shops   | [R] Bank    |" << std::endl;
		std::cout << "| [2] Varrock                                     | [W] World   | [D] Task    |" << std::endl;
		std::cout << "| [3] Falador                                     | [E] Skill   | [F] Slayer  |" << std::endl;
		std::cout << "| [4] Seers' Village                              |-------------|-------------|" << std::endl;
		std::cout << "| [5] Ardougne                                    | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] Karamja                                     | [S] Save    | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";
	} while (getInput());
}