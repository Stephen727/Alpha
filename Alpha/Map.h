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

	void shopDisplay();
	bool getInput();
public:
	void display();
};

#endif