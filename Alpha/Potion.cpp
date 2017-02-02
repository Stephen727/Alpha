#include "Potion.h"
#include "Player.h"


Potion::Potion()
{
}


Potion::Potion(Player *p)
{
	player = p;
}


Potion::~Potion()
{
	player = nullptr;
	delete player;
}


void Potion::drink(int _slot)
{
	Item _item = *player->inventory->getSlot(_slot);

	if (_item.getPotionDefinition() != NULL)
	{
		Item *temp = NULL;

		if (_item.getPotionDefinition()->getReplaceId() != -1)
			temp = new Item(_item.getPotionDefinition()->getReplaceId(), 1);

		player->inventory->remove(_slot);

		if (temp != NULL)
			player->inventory->replace(temp, _slot);

		for (int i = 0; i < _item.getPotionDefinition()->getSkillData().size(); i++)
		{
			player->skills->boostSkill(_item.getPotionDefinition()->getSkillData()[i].add,
				_item.getPotionDefinition()->getSkillData()[i].modifier,
				_item.getPotionDefinition()->getSkillData()[i].skillId,
				_item.getPotionDefinition()->getType());
		}
	}
}