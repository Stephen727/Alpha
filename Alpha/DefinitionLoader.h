#include <fstream>

#ifndef DEFINITIONLOADER_H
#define DEFINITIONLOADER_H

#include "ItemDefinition.h"
#include "ItemBonusDefinition.h"
#include "EquipmentDefinition.h"
#include "FoodDefinition.h"
#include "PotionDefinition.h"
#include "RangedDefinition.h"
#include "WeaponDefinition.h"
#include "NpcDefinition.h"
#include "LootDefinition.h"
#include "ShopDefinition.h"
#include "DungeonDefinition.h"
#include "CityDefinition.h"

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
	std::vector<LootDefinition*> lootDefinition;
	std::vector<ShopDefinition*> shopDefinition;
	std::vector<DungeonDefinition*> dungeonDefinition;
	std::vector<CityDefinition*> cityDefinition;

private:
	void loadItemDefinition();
	void loadItemBonusDefinition();
	void loadEquipmentDefinition();
	void loadFoodDefinition();
	void loadPotionDefinition();
	void loadRangedDefinition();
	void loadWeaponDefinition();
	void loadNpcDefinition();
	void loadLootDefinition();
	void loadShopDefinition();
	void loadDungeonDefinition();
	void loadCityDefinition();
	void loadDefinitions();
};

extern DefinitionLoader definitionLoader;

#endif