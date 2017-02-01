#include "Npc.h"


Npc::Npc()
{
}


Npc::Npc(int _id)
{
	id = _id;
	hitpoints = getNpcDefinition()->getHitpoints();
	delay = 1;
}


Npc::~Npc()
{
}


NpcDefinition* Npc::getNpcDefinition()
{
	for (int i = 0; i < definitionLoader.npcDefinition.size(); i++)
	{
		if (definitionLoader.npcDefinition[i]->getId() == id)
		{
			return definitionLoader.npcDefinition[i];
		}
	}
	return NULL;
}