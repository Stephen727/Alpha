#include "Slayer.h"
#include "Player.h"
#include "Skills.h"

#include <iostream>
#include <fstream>
#include <sstream>


Slayer::Slayer()
{
}


Slayer::Slayer(Player* _player)
{
	player = _player;
	currentTask = nullptr;
	currentSlot = -1;
	currentMaster = -1;
	amount = 0;
}


Slayer::~Slayer()
{
	currentTask = nullptr;
	delete currentTask;

	player = nullptr;
	delete player;
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
	if (currentTask != nullptr)
	{
		if (currentMaster <= id)
			return;
	}

	do
	{
		switch (id)
		{
		case 0:
			currentSlot = rand() % turael.size();
			currentTask = turael[currentSlot];
			amount = rand() % 36 + 15;
			currentMaster = id;
			break;
		case 1:
			currentSlot = rand() % mazchna.size();
			currentTask = mazchna[currentSlot];
			amount = rand() % 36 + 15;
			currentMaster = id;
			break;
		case 2:
			currentSlot = rand() % vannaka.size();
			currentTask = vannaka[currentSlot];
			amount = rand() % 46 + 40;
			currentMaster = id;
			break;
		case 3:
			currentSlot = rand() % chaeldar.size();
			currentTask = chaeldar[currentSlot];
			amount = rand() % 51 + 80;
			currentMaster = id;
			break;
		case 4:
			currentSlot = rand() % nieve.size();
			currentTask = nieve[currentSlot];
			amount = rand() % 66 + 120;
			currentMaster = id;
			break;
		case 5:
			currentSlot = rand() % duradel.size();
			currentTask = duradel[currentSlot];
			amount = rand() % 121 + 130;
			currentMaster = id;
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
		player->skills->addExperience(npc->getNpcDefinition().getHitpoints(), slayer);
		amount--;

		if (!amount)
			currentTask = nullptr;
	}
}

void Slayer::save()
{
	std::ofstream outFile("save.txt", std::ios::app);

	outFile << "Slayer" << std::endl;

	outFile << currentSlot << " " << currentMaster << " " << amount << std::endl << std::endl;

	outFile.close();
}

void Slayer::load()
{
	std::ifstream infile("save.txt");

	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (line == "Slayer")
			infile >> currentSlot >> currentMaster >> amount;
	}

	infile.close();

	switch (currentMaster)
	{
	case 0:
		currentTask = turael[currentSlot];
		break;
	case 1:
		currentTask = mazchna[currentSlot];
		break;
	case 2:
		currentTask = vannaka[currentSlot];
		break;
	case 3:
		currentTask = chaeldar[currentSlot];
		break;
	case 4:
		currentTask = nieve[currentSlot];
		break;
	case 5:
		currentTask = duradel[currentSlot];
		break;
	default:
		return;
		break;
	}
}