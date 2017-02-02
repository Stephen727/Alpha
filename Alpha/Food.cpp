#include "Food.h"
#include "Player.h"


Food::Food()
{
}


Food::Food(Player *p)
{
	player = p;
}


Food::~Food()
{
	player = nullptr;
	delete player;
}


void Food::eat(int _slot)
{
	Item _item = *player->inventory->getSlot(_slot);

	if (_item.getFoodDefinition() != NULL)
	{
		player->skills->heal(_item.getFoodDefinition()->getHeal());
		player->inventory->remove(_slot);
	}
}