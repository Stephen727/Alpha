#include "Player.h"
#include "Combat.h"
#include "Bank.h"
#include "Shop.h"
#include "Map.h"
#include "Slayer.h"

int main()
{
	
	Player *player = new Player("Reginald");
	player->slayer->getNewSlayerTask(0);

	/*
	Shop *shop = new Shop(0);
	shop->enter(player);
	delete shop;

	player->bank->access();

	Combat *combat = new Combat;
	combat->battle(player, 44);

	delete combat;
	delete player;
	*/

	Map map(player);
	map.display();
	std::cin.ignore();

	return 0;
}