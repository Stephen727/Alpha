#include "Npc.h"


Npc::Npc()
{
}


Npc::Npc(int _id)
{
	id = _id;
	setNpcDefinition();
	hitpoints = npcDefinition->getHitpoints();
	delay = 1;
}


Npc::~Npc()
{
	npcDefinition = nullptr;
	delete npcDefinition;
}


void Npc::setNpcDefinition()
{
	for (int i = 0; i < definitionLoader.npcDefinition.size(); i++)
	{
		if (definitionLoader.npcDefinition[i]->getId() == id)
		{
			npcDefinition = definitionLoader.npcDefinition[i];
			return;
		}
	}
	npcDefinition = nullptr;
}