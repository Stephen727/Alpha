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
#include "Combat.h"


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


void Map::dungeonDisplay(int id)
{
	int input;
	do
	{
		system("CLS");
		std::cout << "You enter the " << definitionLoader.dungeonDefinition[id]->getName() << "!" << std::endl << std::endl;

		for (int i = 0; i < definitionLoader.dungeonDefinition[id]->getNpcId().size(); i++)
			std::cout << " [" << i + 1 << "] " << definitionLoader.npcDefinition[definitionLoader.dungeonDefinition[id]->getNpcId()[i]]->getName() << std::endl;

		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > definitionLoader.dungeonDefinition[id]->getNpcId().size()))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
		if (input)
		{
			Combat *combat = new Combat;
			combat->battle(player, definitionLoader.dungeonDefinition[id]->getNpcId()[input - 1]);
			delete combat;
		}
	} while (input);
}

void Map::cityDisplay(int id)
{
	int input;
	do
	{
		system("CLS");
		std::cout << "Welcome to " << definitionLoader.cityDefinition[id]->getName() << "!" << std::endl << std::endl;

		for (int i = 0; i < definitionLoader.cityDefinition[id]->getDungeonId().size(); i++)
			std::cout << " [" << i + 1 << "] " << definitionLoader.dungeonDefinition[definitionLoader.cityDefinition[id]->getDungeonId()[i]]->getName() << std::endl;

		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > definitionLoader.cityDefinition[id]->getDungeonId().size()))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
		if (input)
			dungeonDisplay(definitionLoader.cityDefinition[id]->getDungeonId()[input - 1]);
	} while (input);
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

void Map::slayerDisplay()
{
	int input;
	system("CLS");

	std::cout << " ---Slayer Masters---" << std::endl;
	std::cout << " [1] Turael" << std::endl;
	std::cout << " [2] Mazchna" << std::endl;
	std::cout << " [3] Vannaka" << std::endl;
	std::cout << " [4] Chaeldar" << std::endl;
	std::cout << " [5] Nieve" << std::endl;
	std::cout << " [6] Duradel" << std::endl;
	std::cout << std::endl  << ">";

	while (!(std::cin >> input) || (input < 0 || input > 6))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	if (input)
		player->slayer->getNewSlayerTask(input - 1);
}

void Map::bagDisplay()
{
	int input;
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
}

void Map::gearDisplay()
{
	int input;
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
}

bool Map::getInput()
{
	char select = ' ';
	select = _getch();
	select = toupper(select);

	switch (select)
	{
	case '1':
		cityDisplay(0);
		break;
	case '2':
		cityDisplay(1);
		break;
	case '3':
		cityDisplay(2);
		break;
	case '4':
		cityDisplay(3);
		break;
	case '5':
		cityDisplay(4);
		break;
	case '6':
		cityDisplay(5);
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
		if (player->slayer->hasTask())
		{
			Combat *combat = new Combat;
			combat->battle(player, player->slayer->getCurrentSlayerTaskId());
			delete combat;
		}
		break;
	case 'F': //Slayer
		slayerDisplay();
		break;
	case 'G': //Equipment
		gearDisplay();
		break;
	case 'B': //Inventory
		bagDisplay();
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