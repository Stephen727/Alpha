#include "Prayer.h"
#include "Player.h"
#include "Inventory.h"
#include "Skills.h"


Prayer::Prayer()
{
}


Prayer::Prayer(Player* _player)
{
	player = _player;
}


Prayer::~Prayer()
{
}


bool Prayer::isBone(int slot)
{
	if (player->inventory->getSlot(slot) == nullptr)
		return false;
	
	switch (player->inventory->getSlot(slot)->getId())
	{
	case 23: //Bones
		return true;
		break;
	case 25: //Big Bones
		return true;
		break;
	case 27: //Dragon Bones
		return true;
		break;
	case 29: //Lava Dragon Bones
		return true;
		break;
	default:
		return false;
		break;
	}
}

int Prayer::getExp(int id)
{
	switch (id)
	{
	case 23: //Bones
		return 4;
		break;
	case 25: //Big Bones
		return 15;
		break;
	case 27: //Dragon Bones
		return 72;
		break;
	case 29: //Lava Dragon Bones
		return 85;
		break;
	default:
		return 0;
		break;
	}
}

void Prayer::buryBone(int slot)
{
	if (isBone(slot))
	{
		player->skills->addExperience(getExp(player->inventory->getSlot(slot)->getId()), prayer);
		player->inventory->remove(slot);
	}
}

void Prayer::offerBones()
{
	for (int i = 0; i < 20; i++)
	{
		if (isBone(i))
		{
			player->skills->addExperience(getExp(player->inventory->getSlot(i)->getId()) * 3.5, prayer);
			player->inventory->remove(i);
		}
	}
}