#include "Fishing.h"
#include "Player.h"

#include <time.h>
#include <conio.h>


Fishing::Fishing()
{
}


Fishing::Fishing(Player *p)
{
	player = p;
}


Fishing::~Fishing()
{
}

void Fishing::smallNetBait() //shrimps and anchovies, sardine and herring
{
	if (player->inventory->hasItem(195))
	{
		if (player->skills->getEffect(fishing) >= 15) //shrimp and anchovies
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(131, 1));
				player->skills->addExperience(10, fishing);
			}
			else
			{
				player->inventory->add(new Item(137, 1));
				player->skills->addExperience(40, fishing);
			}
		}
		else if (player->skills->getEffect(fishing) >= 1) //shrimp
		{
			player->inventory->add(new Item(131, 1));
			player->skills->addExperience(10, fishing);
		}
	}
	else if (player->inventory->hasItem(199) && player->inventory->hasItem(207))
	{
		if (player->skills->getEffect(fishing) >= 10) //sardine and herring
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(133, 1));
				player->skills->addExperience(20, fishing);
			}
			else
			{
				player->inventory->add(new Item(135, 1));
				player->skills->addExperience(30, fishing);
			}
			player->inventory->removeItem(207, 1);
		}
		else if (player->skills->getEffect(fishing) >= 5) //sardine
		{
			player->inventory->add(new Item(133, 1));
			player->skills->addExperience(20, fishing);
			player->inventory->removeItem(207, 1);
		}
	}
}

void Fishing::lureBait()
{
	if (player->inventory->hasItem(201) && player->inventory->hasItem(57))
	{
		if (player->skills->getEffect(fishing) >= 30) //trout and salmon
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(141, 1));
				player->skills->addExperience(50, fishing);
			}
			else
			{
				player->inventory->add(new Item(147, 1));
				player->skills->addExperience(70, fishing);
			}
			player->inventory->removeItem(57, 1);
		}
		else if (player->skills->getEffect(fishing) >= 20) //trout
		{
			player->inventory->add(new Item(141, 1));
			player->skills->addExperience(50, fishing);
			player->inventory->removeItem(57, 1);
		}
	}
	else if (player->inventory->hasItem(199) && player->inventory->hasItem(207))
	{
		if (player->skills->getEffect(fishing) >= 25) //pike
		{
			player->inventory->add(new Item(145, 1));
			player->skills->addExperience(60, fishing);
			player->inventory->removeItem(207, 1);
		}
	}
}

void Fishing::cageHarpoon()
{
	if (player->inventory->hasItem(205))
	{
		if (player->skills->getEffect(fishing) >= 40) //lobster
		{
			player->inventory->add(new Item(151, 1));
			player->skills->addExperience(90, fishing);
		}
	}
	else if (player->inventory->hasItem(203))
	{
		if (player->skills->getEffect(fishing) >= 50) //tuna and swordfish
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(149, 1));
				player->skills->addExperience(80, fishing);
			}
			else
			{
				player->inventory->add(new Item(155, 1));
				player->skills->addExperience(100, fishing);
			}
		}
		else if (player->skills->getEffect(fishing) >= 35) //tuna
		{
			player->inventory->add(new Item(149, 1));
			player->skills->addExperience(80, fishing);
		}
	}
}

void Fishing::bigNetHarpoon()
{
	if (player->inventory->hasItem(197))
	{
		if (player->skills->getEffect(fishing) >= 46) //mackerel, cod and bass
		{
			switch (rand() % 3)
			{
			case 0:
				player->inventory->add(new Item(139, 1));
				player->skills->addExperience(20, fishing);
				break;
			case 1:
				player->inventory->add(new Item(143, 1));
				player->skills->addExperience(45, fishing);
				break;
			case 2:
				player->inventory->add(new Item(153, 1));
				player->skills->addExperience(100, fishing);
				break;
			default:
				break;
			}
		}
		else if (player->skills->getEffect(fishing) >= 23) //mackerel and cod
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(139, 1));
				player->skills->addExperience(20, fishing);
			}
			else
			{
				player->inventory->add(new Item(143, 1));
				player->skills->addExperience(45, fishing);
			}
		}
		else if (player->skills->getEffect(fishing) >= 16) //mackerel
		{
			player->inventory->add(new Item(139, 1));
			player->skills->addExperience(20, fishing);
		}
	}
	else if (player->inventory->hasItem(203))
	{
		if (player->skills->getEffect(fishing) >= 76) //shark
		{
			player->inventory->add(new Item(159, 1));
			player->skills->addExperience(110, fishing);
		}
	}
}

void Fishing::harpoonSmallNet()
{
	if (player->inventory->hasItem(203))
	{
		if (player->skills->getEffect(fishing) >= 50) //tuna and swordfish
		{
			if (rand() % 2)
			{
				player->inventory->add(new Item(149, 1));
				player->skills->addExperience(80, fishing);
			}
			else
			{
				player->inventory->add(new Item(155, 1));
				player->skills->addExperience(100, fishing);
			}
		}
		else if (player->skills->getEffect(fishing) >= 35) //tuna
		{
			player->inventory->add(new Item(149, 1));
			player->skills->addExperience(80, fishing);
		}
	}
	else if (player->inventory->hasItem(195))
	{
		if (player->skills->getEffect(fishing) >= 62) //monkfish
		{
			player->inventory->add(new Item(157, 1));
			player->skills->addExperience(120, fishing);
		}
	}
}

void Fishing::wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

bool Fishing::getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return false; // Key Was Hit
	}
	return true; // No keys were pressed
}

void Fishing::fish(int id)
{
	char key = ' ';
	while (player->inventory->getFreeSlots() && getInput(&key))
	{
		std::cout << "You attempt to catch a fish..." << std::endl;

		int fishTimer = (rand() % 10 + 10) - (player->skills->getEffect(fishing) / 9);
		if (fishTimer > 0) wait(fishTimer);

		switch (id)
		{
		case 0:
			smallNetBait();
			break;
		case 1:
			lureBait();
			break;
		case 2:
			cageHarpoon();
			break;
		case 3:
			bigNetHarpoon();
			break;
		case 4:
			harpoonSmallNet();
			break;
		default:
			break;
		}
	}
}