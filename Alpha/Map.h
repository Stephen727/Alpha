#include "Player.h"

#ifndef MAP_H
#define MAP_H

class Map
{
public:
	Map();

	Map(Player*);

	~Map();

private:
	Player *player;

	void dungeonDisplay(int);
	void cityDisplay(int);
	void shopDisplay();
	void worldDisplay();
	void skillDisplay();
	void slayerDisplay();
	void bagDisplay();
	void gearDisplay();
	bool getInput();
public:
	void display();
};

#endif