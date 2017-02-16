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
	int amount, currentMaster;

public:
	bool hasTask();
	void getCurrentSlayerTask();
	int getCurrentSlayerTaskId() { if (hasTask()) return currentTask->getId()[0]; }

	void getNewSlayerTask(int);

	bool isTask(int);
	void checkKill(Npc*);

	void save();
	void load();
};

#endif