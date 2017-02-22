#include "Player.h"

#ifndef TUTORIAL_H
#define TUTORIAL_H

class Tutorial
{
public:
	Tutorial();

	~Tutorial();

private:
	Player *player;
	std::string username;

	void dungeonDisplay(int);
	void cityDisplay(int);

	void mineDisplay();
	void abyssDisplay();
	void pondDisplay();
	void forestDisplay();
	void worldDisplay();

	void rangeDisplay();
	void furnaceDisplay();
	void anvilDisplay();
	void skillDisplay();

	void bagDisplay();
	void gearDisplay();

	void getInput();

	void woodcut();
	void fishCook();
	void mineSmith();
	void combat();
	void fletch();
	void runecraft();
	void herblore();
	void crafting();

	void intro();
	void conclude();
public:
	Player* run();
};

#endif