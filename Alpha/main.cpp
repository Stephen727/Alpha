#include "Player.h"
#include "Combat.h"
#include "Item.h"
#include <iostream>

int main()
{
	Player *player = new Player("Reginald");

	Combat *combat = new Combat;
	combat->battle(player, 38);

	delete combat;
	delete player;

	return 0;
}