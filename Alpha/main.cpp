#include "Player.h"
#include "Combat.h"
#include "Bank.h"
#include "Shop.h"
#include "Map.h"
#include "Slayer.h"

int main()
{
	Player *player = new Player("Reginald");

	Map map(player);
	map.display();

	delete player;

	return 0;
}