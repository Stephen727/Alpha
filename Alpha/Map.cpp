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
#include "Prayer.h"
#include "Magic.h"
#include "Fishing.h"
#include "Cooking.h"
#include "Mining.h"
#include "Smithing.h"
#include "Woodcutting.h"
#include "Crafting.h"
#include "Runecrafting.h"
#include "Wintertodt.h"
#include "Barrows.h"


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
	do
	{
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
	} while (input);
}

void Map::mineDisplay()
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
		std::cout << " [6] Gold Rock" << std::endl;
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

void Map::abyssDisplay()
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

void Map::pondDisplay()
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

void Map::forestDisplay()
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

void Map::worldDisplay()
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

void Map::rangeDisplay()
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

void Map::furnaceDisplay()
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

void Map::anvilDisplay()
{
	int input, tier;
	do
	{
		system("CLS");

		std::cout << " ---Anvil---" << std::endl;
		std::cout << " [1] Bronze" << std::endl;
		std::cout << " [2] Iron" << std::endl;
		std::cout << " [3] Steel" << std::endl;
		std::cout << " [4] Mithril" << std::endl;
		std::cout << " [5] Adamant" << std::endl;
		std::cout << " [6] Rune" << std::endl;
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
		{
			tier = input - 1;

			do
			{
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
				std::cout << " [12] Knives" << std::endl;
				std::cout << " [13] Sq Shield" << std::endl;
				std::cout << " [14] Warhammer" << std::endl;
				std::cout << " [15] Battleaxe" << std::endl;
				std::cout << " [16] Chainbody" << std::endl;
				std::cout << " [17] Kiteshield" << std::endl;
				std::cout << " [18] 2h Sword" << std::endl;
				std::cout << " [19] Platelegs" << std::endl;
				std::cout << " [20] Platebody" << std::endl;
				std::cout << std::endl << ">";

				while (!(std::cin >> input) || (input < 0 || input > 20))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}

				if (input)
					player->smithing->smith(input - 1, tier);
			} while (input);
		}
	} while (input);
}

void Map::skillDisplay()
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
	std::cout << " [7] Slayer Shop" << std::endl;
	std::cout << std::endl  << ">";

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
		if (input == 7)
			player->slayer->slayerShop();
		else
			player->slayer->getNewSlayerTask(input - 1);
	}
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

void Map::minigameDisplay()
{
	int input;
	do
	{
		system("CLS");
		std::cout << " ---Minigames---" << std::endl;
		std::cout << " [1] Wintertodt" << std::endl;
		std::cout << " [2] Barrows" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 2))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input == 1)
		{
			Wintertodt* wintertodt = new Wintertodt;
			wintertodt->play(player);
			delete wintertodt;
		}
		else if (input == 2)
		{
			Barrows* barrows = new Barrows;
			barrows->play(player);
			delete barrows;
		}
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
		worldDisplay();
		break;
	case 'E': //Skill
		skillDisplay();
		break;
	case 'R': //Bank
		player->bank->access();
		break;
	case 'D': //Minigame
		minigameDisplay();
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
	case 'S': //Magic
		int input;
		do
		{
			player->magic->displaySpellBook();
			while (!(std::cin >> input))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}
			player->magic->setCurrentSpell(input - 1);
		} while (input);
		break;
	case '0': //Exit
		player->save();
		std::cout << "Type '0' again to exit the game: ";
		select = ' ';
		select = _getch();
		select = toupper(select);
		if (select == '0') return false;
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
		std::cout << "| [1] Lumbridge                                   |  [Q] Shops  | [R] Bank    |" << std::endl;
		std::cout << "| [2] Varrock                                     |  [W] World  | [D] Minigame|" << std::endl;
		std::cout << "| [3] Falador                                     |  [E] Skill  | [F] Slayer  |" << std::endl;
		std::cout << "| [4] Seers' Village                              |-------------|-------------|" << std::endl;
		std::cout << "| [5] Ardougne                                    |  [G] Gear   | [B] Bag     |" << std::endl;
		std::cout << "| [6] Karamja                                     |  [S] Magic  | [0] Exit    |" << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		std::cout << ">";
		player->save();
	} while (getInput());
}