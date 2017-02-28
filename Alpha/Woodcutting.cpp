#include "Woodcutting.h"
#include "Player.h"
#include "Equipment.h"

#include <time.h>
#include <conio.h>

const std::vector<int> axes = { 12, 14, 16, 18, 20, 22, 24, 26 };
const std::vector<int> axeReq = { 1, 1, 6, 11, 21, 31, 41, 61 };


Woodcutting::Woodcutting()
{
}

Woodcutting::Woodcutting(Player *p)
{
	player = p;
}

Woodcutting::~Woodcutting()
{
}

void Woodcutting::wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}


bool Woodcutting::getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return false; // Key Was Hit
	}
	return true; // No keys were pressed
}

void Woodcutting::chop(int id)
{
	if (!player->inventory->getFreeSlots())
		return;

	int axe = 0;

	for (int i = 0; i < axes.size(); i++)
	{
		if (player->inventory->hasItem(axes[i]))
		{
			if (player->skills->getEffect(woodcutting) >= axeReq[i])
			{
				axe = i + 1;
				break;
			}
		}
		else if (player->equipment->getItem(3) != nullptr)
		{
			if (player->equipment->getItem(3)->getId() == axes[i])
			{
				if (player->skills->getEffect(mining) >= axeReq[i])
				{
					axe = i + 1;
					break;
				}
			}
		}
	}

	if (!axe)
	{
		std::cout << "You can't chop these trees!" << std::endl;

		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cin.ignore();

		return;
	}

	int chopTimer;
	int treeModifier;

	switch (id)
	{
	case 0:
		treeModifier = 1;
		break;
	case 1:
		treeModifier = 3;
		break;
	case 2:
		treeModifier = 5;
		break;
	case 3:
		treeModifier = 6;
		break;
	case 4:
		treeModifier = 8;
		break;
	case 5:
		treeModifier = 12;
		break;
	default:
		return;
		break;
	}

	char key = ' ';
	while (player->inventory->getFreeSlots() && getInput(&key))
	{
		std::cout << "You swing your hatchet at the tree..." << std::endl;

		chopTimer = rand() % 10 + treeModifier - axe;
		if (chopTimer > 0) wait(chopTimer);

		switch (id)
		{
		case 0: //normal
			if (player->skills->getEffect(woodcutting) >= 1)
			{
				player->inventory->add(new Item(0, 1));
				player->skills->addExperience(25, woodcutting);
				std::cout << "You chop a log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		case 1: //oak
			if (player->skills->getEffect(woodcutting) >= 15)
			{
				player->inventory->add(new Item(2, 1));
				player->skills->addExperience(38, woodcutting);
				std::cout << "You chop an oak log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		case 2: //willow
			if (player->skills->getEffect(woodcutting) >= 30)
			{
				player->inventory->add(new Item(4, 1));
				player->skills->addExperience(68, woodcutting);
				std::cout << "You chop a willow log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		case 3: //maple
			if (player->skills->getEffect(woodcutting) >= 45)
			{
				player->inventory->add(new Item(6, 1));
				player->skills->addExperience(100, woodcutting);
				std::cout << "You chop a maple log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		case 4: //yew
			if (player->skills->getEffect(woodcutting) >= 60)
			{
				player->inventory->add(new Item(8, 1));
				player->skills->addExperience(175, woodcutting);
				std::cout << "You chop a yew log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		case 5: //magic
			if (player->skills->getEffect(woodcutting) >= 75)
			{
				player->inventory->add(new Item(10, 1));
				player->skills->addExperience(250, woodcutting);
				std::cout << "You chop a magic log." << std::endl;
			}
			else
				std::cout << "You fail to chop the tree." << std::endl;
			break;
		default:
			break;
		}
	}
}