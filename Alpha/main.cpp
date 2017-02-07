#include "Player.h"
#include "Combat.h"
#include "Bank.h"
#include "Shop.h"

int main()
{
	Player *player = new Player("Reginald");

	Shop *shop = new Shop(0);
	shop->enter(player);
	delete shop;

	player->bank->access();

	Combat *combat = new Combat;
	combat->battle(player, 44);

	delete combat;
	delete player;

	return 0;
}