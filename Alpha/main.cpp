#include "Player.h"
#include "Map.h"

#include <fstream>
#include <iostream>

int main()
{
	Player *player = new Player;

	std::ifstream myfile("save.txt");
	
	if (myfile.is_open())
	{
		myfile.close();
		player->load();
	}
	else
		player->create();

	Map *map = new Map(player);
	map->display();

	delete map;
	delete player;
	
	return 0;
}