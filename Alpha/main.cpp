#include "Player.h"
#include "Combat.h"

int main()
{
	Player player("Reginald");

	Combat combat;
	combat.battle(&player, 38);

	return 0;
}