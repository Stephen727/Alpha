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

	void mineDisplay();
	void abyssDisplay();
	void pondDisplay();
	void forestDisplay();
	void worldDisplay();

	void rangeDisplay();
	void furnaceDisplay();
	void anvilDisplay();
	void skillDisplay();

	void slayerDisplay();

	void bagDisplay();
	void gearDisplay();

	void minigameDisplay();

	bool getInput();
public:
	void display();
};

#endif