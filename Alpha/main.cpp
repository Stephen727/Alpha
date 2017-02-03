#include "Player.h"
#include "Combat.h"

int main()
{
	Player *player = new Player("Reginald");

	Combat *combat = new Combat;
	combat->battle(player, 44);

	delete combat;
	delete player;

	return 0;
}