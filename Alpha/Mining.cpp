#include "Mining.h"
#include "Player.h"
#include "Equipment.h"

#include <time.h>
#include <conio.h>

const std::vector<int> pickaxes = { 236, 238, 240, 242, 244, 246, 248, 250 };
const std::vector<int> pickaxeReq = { 1, 1, 6, 11, 21, 31, 41, 61 };


Mining::Mining()
{
}

Mining::Mining(Player *p)
{
	player = p;
}

Mining::~Mining()
{
}

void Mining::wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

bool Mining::getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return false; // Key Was Hit
	}
	return true; // No keys were pressed
}

void Mining::mine(int id)
{
	if (!player->inventory->getFreeSlots())
		return;

	int pickaxe = 0;

	for (int i = 0; i < pickaxes.size(); i++)
	{
		if (player->inventory->hasItem(pickaxes[i]))
		{
			if (player->skills->getEffect(mining) >= pickaxeReq[i])
			{
				pickaxe = i + 1;
				break;
			}
		}
		else if (player->equipment->getItem(3) != nullptr)
		{
			if (player->equipment->getItem(3)->getId() == pickaxes[i])
			{
				if (player->skills->getEffect(mining) >= pickaxeReq[i])
				{
					pickaxe = i + 1;
					break;
				}
			}
		}
	}

	if (!pickaxe)
	{
		std::cout << "You punch the rock. It doesn't work..." << std::endl;
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cin.ignore();
		return;
	}

	int mineTimer;
	int oreModifier;

	switch (id)
	{
	case 0:
	case 1:
	case 2:
		oreModifier = 1;
		break;
	case 3:
	case 4:
		oreModifier = 5;
		break;
	case 5:
	case 6:
		oreModifier = 6;
		break;
	case 7:
		oreModifier = 7;
	case 8:
		oreModifier = 10;
		break;
	case 9:
		oreModifier = 15;
		break;
	default:
		return;
		break;
	}

	char key = ' ';
	while (player->inventory->getFreeSlots() && getInput(&key))
	{
		std::cout << "You attempt to mine the rock..." << std::endl;

		mineTimer = rand() % 5 + oreModifier - pickaxe;
		if (mineTimer > 0) wait(mineTimer);

		switch (id)
		{
		case 0: //rune essence
			if (player->skills->getEffect(mining) >= 1)
			{
				player->inventory->add(new Item(218, 1));
				player->skills->addExperience(5, mining);
				std::cout << "You mine a rune essence." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 1: //copper ore
			if (player->skills->getEffect(mining) >= 1)
			{
				player->inventory->add(new Item(220, 1));
				player->skills->addExperience(18, mining);
				std::cout << "You mine a copper ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 2: //tin ore
			if (player->skills->getEffect(mining) >= 1)
			{
				player->inventory->add(new Item(222, 1));
				player->skills->addExperience(18, mining);
				std::cout << "You mine a tin ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 3: //iron ore
			if (player->skills->getEffect(mining) >= 15)
			{
				player->inventory->add(new Item(224, 1));
				player->skills->addExperience(35, mining);
				std::cout << "You mine an iron ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 4: //coal
			if (player->skills->getEffect(mining) >= 30)
			{
				player->inventory->add(new Item(226, 1));
				player->skills->addExperience(50, mining);
				std::cout << "You mine a coal ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 5: //gold ore
			if (player->skills->getEffect(mining) >= 40)
			{
				player->inventory->add(new Item(228, 1));
				player->skills->addExperience(65, mining);
				std::cout << "You mine a gold ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 6: //gem rock
			if (player->skills->getEffect(mining) >= 40)
			{
				int gem = rand() % 100;

				if (gem < 77)
				{
					player->inventory->add(new Item(842, 1));
					std::cout << "You mine a jade." << std::endl;
				}
				else if (gem < 86)
				{
					player->inventory->add(new Item(844, 1));
					std::cout << "You mine a sapphire." << std::endl;
				}
				else if (gem < 91)
				{
					player->inventory->add(new Item(846, 1));
					std::cout << "You mine a emerald." << std::endl;
				}
				else if (gem < 96)
				{
					player->inventory->add(new Item(848, 1));
					std::cout << "You mine a ruby." << std::endl;
				}
				else if (gem < 100)
				{
					player->inventory->add(new Item(850, 1));
					std::cout << "You mine a diamond." << std::endl;
				}
				else
					std::cout << "You crush the gem." << std::endl;

				player->skills->addExperience(65, mining);
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 7: //mithril ore
			if (player->skills->getEffect(mining) >= 55)
			{
				player->inventory->add(new Item(230, 1));
				player->skills->addExperience(80, mining);
				std::cout << "You mine a mithril ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 8: //adamantite ore
			if (player->skills->getEffect(mining) >= 70)
			{
				player->inventory->add(new Item(232, 1));
				player->skills->addExperience(95, mining);
				std::cout << "You mine an adamantite ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		case 9: //runite ore
			if (player->skills->getEffect(mining) >= 85)
			{
				player->inventory->add(new Item(234, 1));
				player->skills->addExperience(125, mining);
				std::cout << "You mine a runite ore." << std::endl;
			}
			else
				std::cout << "You fail to mine the rock..." << std::endl;
			break;
		default:
			break;
		}
	}
}