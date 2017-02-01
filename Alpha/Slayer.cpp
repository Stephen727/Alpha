#include "Slayer.h"
#include "Player.h"
#include "Skills.h"
#include <iostream>


Slayer::Slayer()
{
}


Slayer::Slayer(Player* _player)
{
	player = _player;
	currentTask = nullptr;
}


Slayer::~Slayer()
{
}


bool Slayer::hasTask()
{
	return currentTask != nullptr;
}

bool Slayer::isTask(int id)
{
	if (hasTask())
	{
		for (int i = 0; i < currentTask->getId().size(); i++)
			if (id == currentTask->getId()[i])
				return true;
	}
	return false;
}

void Slayer::getCurrentSlayerTask()
{
	if (hasTask())
		std::cout << "Your current slayer task is to kill " << amount << " " << currentTask->getName() << "." << std::endl;
	else
		std::cout << "You currently have no slayer task." << std::endl;
}

void Slayer::getNewSlayerTask(int id)
{
	do
	{
		switch (id)
		{
		case 0:
			currentTask = turael[rand() % turael.size()];
			amount = rand() % 36 + 15;
			break;
		case 1:
			currentTask = mazchna[rand() % mazchna.size()];
			amount = rand() % 36 + 15;
			break;
		case 2:
			currentTask = vannaka[rand() % vannaka.size()];
			amount = rand() % 46 + 40;
			break;
		case 3:
			currentTask = chaeldar[rand() % chaeldar.size()];
			amount = rand() % 51 + 80;
			break;
		case 4:
			currentTask = nieve[rand() % nieve.size()];
			amount = rand() % 66 + 120;
			break;
		case 5:
			currentTask = duradel[rand() % duradel.size()];
			amount = rand() % 121 + 130;
			break;
		default:
			return;
			break;
		}
	} while (currentTask->getLevel() > player->skills->getLevel(slayer));
}

void Slayer::checkKill(Npc* npc)
{
	if (isTask(npc->getId()))
	{
		player->skills->addExperience(npc->getNpcDefinition()->getHitpoints(), slayer);
		amount--;

		if (!amount)
			currentTask = nullptr;
	}
}