#include "Player.h"
#include "Combat.h"
#include "Bank.h"
#include "Shop.h"
#include "Map.h"
#include "Slayer.h"

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