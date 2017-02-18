#include "Player.h"
#include "Map.h"

int main()
{
	Player *player = new Player;
	player->load();

	Map *map = new Map(player);
	map->display();

	delete map;
	delete player;
	
	return 0;
}