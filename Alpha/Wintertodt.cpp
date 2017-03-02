#include "Wintertodt.h"

#include "Combat.h"
#include "Skills.h"
#include "Equipment.h"
#include "Inventory.h"
#include "UseItem.h"

#include "conio.h"


Wintertodt::Wintertodt()
{
	npc = new Npc(121);
}


Wintertodt::~Wintertodt()
{
	delete npc;
}


void Wintertodt::fightBruma(Player* player)
{
	Combat *combat = new Combat;

	if (player->skills->getCombatLevel() < 40)
		combat->battle(player, 117);
	else if (player->skills->getCombatLevel() < 70)
		combat->battle(player, 118);
	else if (player->skills->getCombatLevel() < 100)
		combat->battle(player, 119);
	else
		combat->battle(player, 120);

	delete combat;
}

void Wintertodt::fightWintertodt(Player* player)
{
	Combat *combat = new Combat;
	combat->battle(player, npc);
	delete combat;
}

void Wintertodt::bagDisplay(Player* player)
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

void Wintertodt::gearDisplay(Player* player)
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

bool Wintertodt::getInput(Player* player)
{
	char select = ' ';
	select = _getch();
	select = toupper(select);

	switch (select)
	{
	case '1':
		fightBruma(player);
		break;
	case '2':
		fightWintertodt(player);
		break;
	case 'G': //Equipment
		gearDisplay(player);
		break;
	case 'B': //Inventory
		bagDisplay(player);
		break;
	case 'S': //Stats
		int input;
		do
		{
			player->skills->displayStats();
			while (!(std::cin >> input))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}
		} while (input);
		break;
	case '0': //Exit
		player->save();
		std::cout << "Type '0' again to exit the minigame: ";
		select = ' ';
		select = _getch();
		select = toupper(select);
		if (select == '0') return false;
		break;
	default:
		getInput(player);
		break;
	}

	return true;
}

void Wintertodt::play(Player* player)
{
	int input;
	
	do
	{
		std::string username = player->getName();
		username.resize(20);

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|      Kill the Bruma and collect their torches!                              |" << std::endl;
		std::cout << "|      It's the only way you'll be able to fight the                          |" << std::endl;
		std::cout << "|      Wintertodt.                                                            |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|      Once you've collect a few, come back here and                          |" << std::endl;
		std::cout << "|      toss them at the Wintertodt to weaken it. Once                         |" << std::endl;
		std::cout << "|      defeated, the pyromancers should reward you.                           |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|             WELCOME TO THE WINTERTODT CAMP!                                 |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Fight Bruma                                                             |" << std::endl;
		std::cout << "| [2] Fight Wintertodt                                                        |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                 |---------------------------|" << std::endl;
		std::cout << "|                                                 | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "|                                                 | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

	} while (getInput(player) && npc->getHitpoints());

	if (player->equipment->getItem(3) != nullptr)
	{
		if (player->equipment->getItem(3)->getId() == 1003)
			player->equipment->clearSlot(3);
	}

	for (int i = 0; i < 20; i++)
	{
		if (player->inventory->getSlot(i) != nullptr)
			if (player->inventory->getSlot(i)->getId() == 1003)
				player->inventory->remove(i);
	}
}