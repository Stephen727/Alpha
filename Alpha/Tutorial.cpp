#include "Tutorial.h"

#include <iostream>
#include <string>
#include <conio.h>

#include "Inventory.h"
#include "Bank.h"
#include "Equipment.h"
#include "Skills.h"
#include "UseItem.h"
#include "Combat.h"
#include "Prayer.h"
#include "Fishing.h"
#include "Cooking.h"
#include "Mining.h"
#include "Smithing.h"
#include "Woodcutting.h"
#include "Crafting.h"
#include "Runecrafting.h"


Tutorial::Tutorial()
{
	player = nullptr;
}


Tutorial::~Tutorial()
{
}


void Tutorial::dungeonDisplay(int id)
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

void Tutorial::cityDisplay(int id)
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

void Tutorial::mineDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << "   ---Mine---" << std::endl;
		std::cout << " [1] Essence Rock" << std::endl;
		std::cout << " [2] Copper Rock" << std::endl;
		std::cout << " [3] Tin Rock" << std::endl;
		std::cout << " [4] Iron Rock" << std::endl;
		std::cout << " [5] Coal Rock" << std::endl;
		std::cout << " [7] Gem Rock" << std::endl;
		std::cout << " [8] Mithril Rock" << std::endl;
		std::cout << " [9] Adamant Rock" << std::endl;
		std::cout << " [10] Rune Rock" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 10))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input)
			player->mining->mine(input - 1);

	} while (input);
}

void Tutorial::abyssDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << " ---Abyss---" << std::endl;
		std::cout << " [1] Air Altar" << std::endl;
		std::cout << " [2] Mind Altar" << std::endl;
		std::cout << " [3] Water Altar" << std::endl;
		std::cout << " [4] Earth Altar" << std::endl;
		std::cout << " [5] Fire Altar" << std::endl;
		std::cout << " [6] Cosmic Altar" << std::endl;
		std::cout << " [7] Chaos Altar" << std::endl;
		std::cout << " [8] Nature Altar" << std::endl;
		std::cout << " [9] Death Altar" << std::endl;
		std::cout << " [10] Blood Altar" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 10))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
		if (input)
			player->runecrafting->runecraft(input - 1);

	} while (input);
}

void Tutorial::pondDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << "     ---Pond---" << std::endl;
		std::cout << " [1] Small Net / Bait" << std::endl;
		std::cout << " [2] Lure / Bait" << std::endl;
		std::cout << " [3] Cage / Harpoon" << std::endl;
		std::cout << " [4] Big Net / Harpoon" << std::endl;
		std::cout << " [5] Harpoon / Small Net" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 5))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input)
			player->fishing->fish(input - 1);
	} while (input);
}

void Tutorial::forestDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << " ---Forest---" << std::endl;
		std::cout << " [1] Tree" << std::endl;
		std::cout << " [2] Oak Tree" << std::endl;
		std::cout << " [3] Willow Tree" << std::endl;
		std::cout << " [4] Maple Tree" << std::endl;
		std::cout << " [5] Yew Tree" << std::endl;
		std::cout << " [6] Magic Tree" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 6))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input)
			player->woodcutting->chop(input - 1);

	} while (input);
}

void Tutorial::worldDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << " ---World---" << std::endl;
		std::cout << " [1] Mine" << std::endl;
		std::cout << " [2] Abyss" << std::endl;
		std::cout << " [3] Pond" << std::endl;
		std::cout << " [4] Forest" << std::endl;
		std::cout << " [5] Flax Field" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 5))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		switch (input)
		{
		case 1:
			mineDisplay();
			break;
		case 2:
			abyssDisplay();
			break;
		case 3:
			pondDisplay();
			break;
		case 4:
			forestDisplay();
			break;
		case 5:
			player->crafting->pickFlax();
			break;
		default:
			break;
		}
	} while (input);
}

void Tutorial::rangeDisplay()
{
	system("CLS");
	std::cout << "\t---Range---" << std::endl;

	for (int i = 0; i < 20; i++)
		player->cooking->cook(i);

	std::cout << std::endl << ">";

	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.ignore();
}

void Tutorial::furnaceDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << " ---Furnace---" << std::endl;
		std::cout << " [1] Bronze" << std::endl;
		std::cout << " [2] Iron" << std::endl;
		std::cout << " [3] Steel" << std::endl;
		std::cout << " [4] Gold" << std::endl;
		std::cout << " [5] Mithril" << std::endl;
		std::cout << " [6] Adamant" << std::endl;
		std::cout << " [7] Rune" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 7))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input)
			player->smithing->smelt(input - 1);
	} while (input);
}

void Tutorial::anvilDisplay()
{
	int input, tier;
	do
	{
		system("CLS");

		std::cout << " ---Anvil---" << std::endl;
		std::cout << " [1] Bronze" << std::endl;
		std::cout << " [2] Iron" << std::endl;
		std::cout << " [3] Steel" << std::endl;
		std::cout << " [4] Gold" << std::endl;
		std::cout << " [5] Mithril" << std::endl;
		std::cout << " [6] Adamant" << std::endl;
		std::cout << " [7] Rune" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 7))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input)
		{
			tier = input - 1;

			system("CLS");
			std::cout << " ---Anvil---" << std::endl;
			std::cout << " [1] Dagger" << std::endl;
			std::cout << " [2] Hatchet" << std::endl;
			std::cout << " [3] Mace" << std::endl;
			std::cout << " [4] Med Helm" << std::endl;
			std::cout << " [5] Bolts" << std::endl;
			std::cout << " [6] Sword" << std::endl;
			std::cout << " [7] Arrowtips" << std::endl;
			std::cout << " [8] Scimitar" << std::endl;
			std::cout << " [9] C'bow Limb" << std::endl;
			std::cout << " [10] Longsword" << std::endl;
			std::cout << " [11] Full Helm" << std::endl;
			std::cout << " [12] Sq Shield" << std::endl;
			std::cout << " [13] Warhammer" << std::endl;
			std::cout << " [14] Battleaxe" << std::endl;
			std::cout << " [15] Chainbody" << std::endl;
			std::cout << " [16] 2h Sword" << std::endl;
			std::cout << " [17] Platelegs" << std::endl;
			std::cout << " [18] Platebody" << std::endl;
			std::cout << std::endl << ">";

			while (!(std::cin >> input) || (input < 0 || input > 18))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}

			if (input)
				player->smithing->smith(input - 1, tier);
		}
	} while (input);
}

void Tutorial::skillDisplay()
{
	int input;
	do
	{
		system("CLS");

		std::cout << " ---Skilling---" << std::endl;
		std::cout << " [1] Temple" << std::endl;
		std::cout << " [2] Range" << std::endl;
		std::cout << " [3] Furnace" << std::endl;
		std::cout << " [4] Anvil" << std::endl;
		std::cout << " [5] Tanner" << std::endl;
		std::cout << " [6] Spinning Wheel" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 6))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		switch (input)
		{
		case 1: //Temple
			player->skills->restore(prayer);

			system("CLS");
			std::cout << "You visit the temple..." << std::endl;

			player->prayer->offerBones();

			std::cout << std::endl << ">";

			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			std::cin.ignore();
			break;
		case 2: //Range
			rangeDisplay();
			break;
		case 3: //Furnace
			furnaceDisplay();
			break;
		case 4: //Anvil
			anvilDisplay();
			break;
		case 5: //Tanner
			system("CLS");
			std::cout << "You visit the tanner..." << std::endl;
			player->crafting->tan();

			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			std::cin.ignore();
			break;
		case 6: //Spinng wheel
			player->crafting->spinFlax();
			break;
		default:
			break;
		}
	} while (input);
}

void Tutorial::bagDisplay()
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

void Tutorial::gearDisplay()
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

void Tutorial::getInput()
{
	char select = ' ';
	select = _getch();
	select = toupper(select);

	switch (select)
	{
	case '1':
		cityDisplay(0);
		break;
	case 'W': //World
		worldDisplay();
		break;
	case 'E': //Skill
		skillDisplay();
		break;
	case 'G': //Equipment
		gearDisplay();
		break;
	case 'B': //Inventory
		bagDisplay();
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
		break;
	default:
		break;
	}
}

void Tutorial::woodcut()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(12))
		{
			if (player->equipment->getItem(3) == nullptr)
				player->inventory->add(new Item(12, 1));
			else if (player->equipment->getItem(3)->getId() != 12)
				player->inventory->add(new Item(12, 1));
		}

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|      Woodcutting is a gathering skill that primarily involves chopping      |" << std::endl;
		std::cout << "|      trees to obtain logs used in the Fletching.To chop trees, go to        |" << std::endl;
		std::cout << "|      the <[W] World> tab.                                                   |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|      I've given you a hatchet. To cancel chopping the tree at any time      |" << std::endl;
		std::cout << "|      just press any key on your keyboard.                                   |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|      Bring me back some logs to move on to the next lesson.                 |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(0));
}

void Tutorial::fishCook()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(12))
			player->inventory->add(new Item(195, 1));

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|     Fishing is a skill which involves catching fish Caught fish may be      |" << std::endl;
		std::cout << "|     cooked through the Cooking skill to create food which may be            |" << std::endl;
		std::cout << "|     used later to regain hitpoints during combat.To fish, go to the         |" << std::endl;
		std::cout << "|     <[W] World> tab.                                                        |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|     I've given you a small net. To cancel your attempt at fishing at any    |" << std::endl;
		std::cout << "|     time just press any key on your keyboard.                               |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|     Bring me back some raw shrimp to move on to the next lesson.            |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";
	
		getInput();

	} while (!player->inventory->hasItem(131));

	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(131))
			player->inventory->add(new Item(131, 1));

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|     Cooking is a skill that allows a player to cook raw food into food      |" << std::endl;
		std::cout << "|     that you can eat.To cook food, go to the <[E] Skill> tab, and           |" << std::endl;
		std::cout << "|     use the Range.                                                          |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|     Bring me back what you cooked to move on to the next lesson.            |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(163) && !player->inventory->hasItem(216));
}

void Tutorial::mineSmith()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(236))
		{
			if (player->equipment->getItem(3) == nullptr)
				player->inventory->add(new Item(236, 1));
			else if (player->equipment->getItem(3)->getId() != 236)
				player->inventory->add(new Item(236, 1));
		}

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Mining is a skill that allows players to obtain ores from rocks.         |" << std::endl;
		std::cout << "|    With ores, a player can then either smelt bars and make                  |" << std::endl;
		std::cout << "|    equipment using the Smithing skill.To mine, go to the                    |" << std::endl;
		std::cout << "|    <[W] World> tab.                                                         |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you a pickaxe. To cancel mining at any time just press        |" << std::endl;
		std::cout << "|    any key on your keyboard.                                                |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Bring me back some tin and copper ore to move on to the next             |" << std::endl;
		std::cout << "|    lesson.                                                                  |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(220) || !player->inventory->hasItem(222));

	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(266))
			player->inventory->add(new Item(266, 1));
		
		if (!player->inventory->hasItem(252))
		{
			if (!player->inventory->hasItem(220))
				player->inventory->add(new Item(220, 1));

			if (!player->inventory->hasItem(222))
				player->inventory->add(new Item(222, 1));
		}

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Smithing is a production skill through which players may create          |" << std::endl;
		std::cout << "|    a wide variety of metal items from ore and metal bars.To smelt           |" << std::endl;
		std::cout << "|    ore, go to the Furnace in the <[E] Skill> tab.To smith items,            |" << std::endl;
		std::cout << "|    go to the Anvil in the <[E] Skill> tab.                                  |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you a hammer so you can use the anvil.                        |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Bring me back a bronze dagger to move on to the next lesson.             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(268));
}

void Tutorial::combat()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->skills->getExperience(magic))
		{
			if (!player->inventory->hasItem(539))
				player->inventory->add(new Item(539, 30)); //Air runes

			if (!player->inventory->hasItem(540))
				player->inventory->add(new Item(540, 30)); //Mind runes
		}

		if (!player->skills->getExperience(ranged))
		{
			if (!player->inventory->hasItem(44))
			{
				if (player->equipment->getItem(3) == nullptr)
					player->inventory->add(new Item(44, 1));
				else if (player->equipment->getItem(3)->getId() != 44)
					player->inventory->add(new Item(44, 1));
			}

			if (!player->inventory->hasItem(65))
			{
				if (player->equipment->getItem(10) == nullptr)
					player->inventory->add(new Item(65, 25));
				else if (player->equipment->getItem(10)->getId() != 65)
					player->inventory->add(new Item(65, 25));
			}
		}

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Go into Lumbridge, and then the Farm.I need you to kill some             |" << std::endl;
		std::cout << "|    chickens to gather feathers.Chickens are weak creatures, so              |" << std::endl;
		std::cout << "|    you shouldn't have any difficulties. You can even use your new           |" << std::endl;
		std::cout << "|    dagger that you made.Once you've killed a chicken, check your            |" << std::endl;
		std::cout << "|    inventory.You get bones that you can bury for prayer experience.         |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    To bury the bones type the number of the slot they are in and a          |" << std::endl;
		std::cout << "|    'u'.This is also how you equip items.Kill the chickens using all         |" << std::endl;
		std::cout << "|    three combat stances : melee, ranged, and magic.I've given you           |" << std::endl;
		std::cout << "|    everything you need.                                                     |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->skills->getExperience(prayer) || !player->inventory->hasItem(57) || !player->skills->getExperience(ranged) || !player->skills->getExperience(magic) ||
		(!player->skills->getExperience(attack) && !player->skills->getExperience(strength) && !player->skills->getExperience(defense)));
}

void Tutorial::fletch()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(129))
			player->inventory->add(new Item(129, 1));

		if (!player->inventory->hasItem(58))
		{
			if (!player->inventory->hasItem(57))
				player->inventory->add(new Item(57, 15));
			
			if (!player->inventory->hasItem(0))
				player->inventory->add(new Item(0, 1));
		}
		else if (!player->inventory->hasItem(56))
		{
			if (!player->inventory->hasItem(0))
				player->inventory->add(new Item(0, 1));
		}

		if (!player->inventory->hasItem(59))
			player->inventory->add(new Item(59, 15));

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Fletching is a skill which allows the player to create various types     |" << std::endl;
		std::cout << "|    of ranged weapons and their ammunition.To fletch, go into your           |" << std::endl;
		std::cout << "|    inventory and type the number of the first slot, followed by a 'f',      |" << std::endl;
		std::cout << "|    and then the number of the second slot.                                  |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you a knife and some bronze arrowtips. I want you to          |" << std::endl;
		std::cout << "|    fletch me some arrows.First turn the logs into arrowshafts.Then          |" << std::endl;
		std::cout << "|    add feathers to create headless arrows.Lastly attach the bronze          |" << std::endl;
		std::cout << "|    arrowtips.                                                               |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(65) && player->equipment->getItem(10) == nullptr);
}

void Tutorial::runecraft()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(519))
			player->inventory->add(new Item(519, 1));

		if (!player->inventory->hasItem(218))
			player->inventory->add(new Item(218, 1));

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Runecraft is a skill that allows players to craft their own runes for    |" << std::endl;
		std::cout << "|    Magic spells.Altars are located in the <[W] World> tab, in a             |" << std::endl;
		std::cout << "|    location called The Abyss.                                               |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you an air talisman, this will allow you to access the        |" << std::endl;
		std::cout << "|    air altar.I've also given you some rune essence, you can convert         |" << std::endl;
		std::cout << "|    them into air runes now.                                                 |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(539));
}

void Tutorial::herblore()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasItem(573))
			player->inventory->add(new Item(573, 1));

		if (!player->inventory->hasItem(575))
			player->inventory->add(new Item(575, 1));
		
		if (!player->inventory->hasItem(595))
			player->inventory->add(new Item(595, 1));

		

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Herblore is a skill that involves brewing potions from a vial, an        |" << std::endl;
		std::cout << "|    herb, and a tertiary ingredient.To brew, you need a vial. Once           |" << std::endl;
		std::cout << "|    you have a vial, in your inventory type the slot number of the vial,     |" << std::endl;
		std::cout << "|    followed by a 'u'.This will bring up the brewing menu.                   |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you some ingredients, bring me an attack potion and           |" << std::endl;
		std::cout << "|    we'll move on to the next lesson.                                        |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(623) && !player->inventory->hasItem(621) && !player->inventory->hasItem(619));
}

void Tutorial::crafting()
{
	player->inventory->clear();
	player->equipment->clear();

	do
	{
		if (!player->inventory->hasAmount(516))
			player->inventory->add(new Item(516, 30));
		
		if (!player->inventory->hasAmount(448) && !player->inventory->hasAmount(450))
			player->inventory->add(new Item(448, 1));
		
		if (!player->inventory->hasAmount(514))
			player->inventory->add(new Item(514, 1));

		if (!player->inventory->hasAmount(515))
			player->inventory->add(new Item(515, 1));

		system("CLS");
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                  " << username << "                                       |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    Crafting is a skill that allows players to create ranged armor from      |" << std::endl;
		std::cout << "|    leathers.To creaft, go into your inventory and type the slot number      |" << std::endl;
		std::cout << "|    of the needle, followed by a 'c', and then the number of the second      |" << std::endl;
		std::cout << "|    slot. More options will appear at the bottom of your screen.             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    I've given you some supplies, craft me a pair of leather gloves.         |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|    First you need to bring the cowhide to the tanner in <[E] Skill> tab!    |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "|                                                                             |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
		std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
		std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
		std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
		std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
		std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";

		getInput();

	} while (!player->inventory->hasItem(454));
}

void Tutorial::intro()
{
	system("CLS");
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                  " << username << "                                       |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    Welcome to the tutorial! This is a place for you to learn the ropes.     |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    The basic controls for the inventory are 'd' to drop (1d to drop         |" << std::endl;
	std::cout << "|    the item in slot one), 'u' to use an item (1u uses the item on slot      |" << std::endl;
	std::cout << "|    one) and 's'  to swap items (1s2 swaps slots 1 and 2). Type '0'          |" << std::endl;
	std::cout << "|    to back out of any menu.                                                 |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    Press any button to continue on...                                       |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
	std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
	std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
	std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
	std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
	std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";

	std::cin.ignore();
}

void Tutorial::conclude()
{
	system("CLS");
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                  " << username << "                                       |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    You have completed the tutorial!                                         |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    If you have any further questions, each skill has a ton of               |" << std::endl;
	std::cout << "|    information about them online. Google 'OSRS ...'                         |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    Good luck!                                                               |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|    Press any button to continue on...                                       |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "|                                                                             |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "| [1] Lumbridge                                   | [Q] LOCKED  | [R] LOCKED  |" << std::endl;
	std::cout << "| [2] --LOCKED--                                  | [W] World   | [D] LOCKED  |" << std::endl;
	std::cout << "| [3] --LOCKED--                                  | [E] Skill   | [F] LOCKED  |" << std::endl;
	std::cout << "| [4] --LOCKED--                                  |-------------|-------------|" << std::endl;
	std::cout << "| [5] --LOCKED--                                  | [G] Gear    | [B] Bag     |" << std::endl;
	std::cout << "| [6] --LOCKED--                                  | [S] Stats   | [0] Exit    |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";

	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.ignore();
}

Player* Tutorial::run()
{
	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	do
	{
		system("CLS");
		std::cout << "Please enter a username: ";

		std::getline(std::cin, username);

		if (username.length() < 1 || username.length() > 15)
		{
			std::cout << "Username must be between 3 and 15 characters in length." << std::endl;
			system("PAUSE");
		}
	} while (username.length() < 3 || username.length() > 15);

	player = new Player(username);
	username.resize(20);

	intro();
	woodcut();
	fishCook();
	mineSmith();
	combat();
	fletch();
	runecraft();
	herblore();
	crafting();
	conclude();

	player->inventory->clear();
	player->equipment->clear();
	player->giveStarterPack();

	return player;
}