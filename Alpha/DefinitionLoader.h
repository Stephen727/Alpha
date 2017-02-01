#include <fstream>

#include "ItemDefinition.h"
#include "ItemBonusDefinition.h"
#include "EquipmentDefinition.h"
#include "FoodDefinition.h"
#include "PotionDefinition.h"
#include "RangedDefinition.h"
#include "WeaponDefinition.h"
#include "NpcDefinition.h"

#ifndef DEFINITIONLOADER_H
#define DEFINITIONLOADER_H

class DefinitionLoader
{
public:
	DefinitionLoader();

	~DefinitionLoader();

	std::vector<ItemDefinition*> itemDefinition;
	std::vector<ItemBonusDefinition*> itemBonusDefinition;
	std::vector<EquipmentDefinition*> equipmentDefinition;
	std::vector<FoodDefinition*> foodDefinition;
	std::vector<PotionDefinition*> potionDefinition;
	std::vector<RangedDefinition*> rangedDefinition;
	std::vector<WeaponDefinition*> weaponDefinition;
	std::vector<NpcDefinition*> npcDefinition;

private:
	void loadItemDefinition();
	void loadItemBonusDefinition();
	void loadEquipmentDefinition();
	void loadFoodDefinition();
	void loadPotionDefinition();
	void loadRangedDefinition();
	void loadWeaponDefinition();
	void loadNpcDefinition();
	void loadDefinitions();
};

extern DefinitionLoader definitionLoader;

#endif