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

public:
	void display();
};

#endif