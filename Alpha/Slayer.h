#include "SlayerTask.h"
#include "Npc.h"

#ifndef SLAYER_H
#define SLAYER_H

class Player;

class Slayer
{
public:
	Slayer();

	Slayer(Player*);

	~Slayer();

private:
	Player* player;
	SlayerTask* currentTask;
	int amount;

	bool isTask(int);

public:
	bool hasTask();
	void getCurrentSlayerTask();

	void getNewSlayerTask(int);

	void checkKill(Npc*);
};

#endif