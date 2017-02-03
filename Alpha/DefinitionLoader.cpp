#include "DefinitionLoader.h"
#include <iostream>
#include <time.h>
#include <sstream>

#include "Item.h"

DefinitionLoader::DefinitionLoader()
{
	loadDefinitions();
}


DefinitionLoader::~DefinitionLoader()
{
	for (auto it = itemDefinition.begin(); it != itemDefinition.end();)
			it = itemDefinition.erase(it);

	for (auto it = itemBonusDefinition.begin(); it != itemBonusDefinition.end();)
		it = itemBonusDefinition.erase(it);

	for (auto it = equipmentDefinition.begin(); it != equipmentDefinition.end();)
		it = equipmentDefinition.erase(it);

	for (auto it = foodDefinition.begin(); it != foodDefinition.end();)
		it = foodDefinition.erase(it);

	for (auto it = potionDefinition.begin(); it != potionDefinition.end();)
		it = potionDefinition.erase(it);

	for (auto it = rangedDefinition.begin(); it != rangedDefinition.end();)
		it = rangedDefinition.erase(it);

	for (auto it = weaponDefinition.begin(); it != weaponDefinition.end();)
		it = weaponDefinition.erase(it);

	for (auto it = npcDefinition.begin(); it != npcDefinition.end();)
		it = npcDefinition.erase(it);
}

void DefinitionLoader::loadItemDefinition()
{
	std::ifstream infile("ItemDefinition.txt");
	if (!infile) std::cerr << "ItemDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading item definitions..." << std::endl;

	std::string _name;
	int _id;
	bool _stackable, _note;
	int _noteId, _alchemyPrice, _generalPrice;

	while (infile >> _name >> _id >> _stackable >> _note >> _noteId >> _alchemyPrice >> _generalPrice)
	{
		itemDefinition.push_back(new ItemDefinition(_name, _id, _stackable, _note, _noteId, _alchemyPrice, _generalPrice));
	}

	infile.close();
	std::cout << "Item definitions loaded: " << itemDefinition.size() << std::endl;
}

void DefinitionLoader::loadItemBonusDefinition()
{
	std::ifstream infile("ItemBonusDefinition.txt");
	if (!infile) std::cerr << "ItemBonusDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading item bonus definitions..." << std::endl;

	int _id, _meleeatt, _magicatt, _rangeatt, _meleedef, _magicdef, _rangedef, _str, _prayer;

	while (infile >> _id >> _meleeatt >> _magicatt >> _rangeatt >> _meleedef >> _magicdef >> _rangedef >> _str >> _prayer)
	{
		itemBonusDefinition.push_back(new ItemBonusDefinition(_id, _meleeatt, _magicatt, _rangeatt, _meleedef, _magicdef, _rangedef, _str, _prayer));
	}

	infile.close();
	std::cout << "Item bonus definitions loaded: " << itemBonusDefinition.size() << std::endl;
}

void DefinitionLoader::loadEquipmentDefinition()
{
	std::ifstream infile("EquipmentDefinition.txt", std::ifstream::in);
	if (!infile) std::cerr << "EquipmentDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading equipment definitions..." << std::endl;

	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int _id, _slot, _skillId, _skillReq;
		char delim = ',';
		std::vector<EquipmentDefinition::SkillData> _skillData;
		iss >> _id >> _slot;

		while (iss >> _skillId >> delim >> _skillReq)
			_skillData.push_back(EquipmentDefinition::SkillData(_skillId, _skillReq));

		equipmentDefinition.push_back(new EquipmentDefinition(_id, _slot, _skillData));
		_skillData.clear();
	}

	infile.close();
	std::cout << "Equipment definitions loaded: " << equipmentDefinition.size() << std::endl;
}

void DefinitionLoader::loadFoodDefinition()
{
	std::ifstream infile("FoodDefinition.txt");
	if (!infile) std::cerr << "FoodDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading food definitions..." << std::endl;

	int _id, _heal;

	while (infile >> _id >> _heal)
	{
		foodDefinition.push_back(new FoodDefinition(_id, _heal));
	}

	infile.close();
	std::cout << "Food definitions loaded: " << foodDefinition.size() << std::endl;
}

void DefinitionLoader::loadPotionDefinition()
{
	std::ifstream infile("PotionDefinition.txt", std::ifstream::in);
	if (!infile) std::cerr << "PotionDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading potion definitions..." << std::endl;

	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int _id, _replaceId, _type, _skillId, _add;
		double _modifier;
		char delim = ',';
		std::vector<PotionDefinition::SkillData> _skillData;
		iss >> _id >> _replaceId, _type;

		while (iss >> _skillId >> _add >> delim >> _modifier)
			_skillData.push_back(PotionDefinition::SkillData(_skillId, _add, _modifier));

		potionDefinition.push_back(new PotionDefinition(_id, _replaceId, _type, _skillData));
		_skillData.clear();
	}

	infile.close();
	std::cout << "Potion definitions loaded: " << potionDefinition.size() << std::endl;
}

void DefinitionLoader::loadRangedDefinition()
{
	std::ifstream infile("RangedDefinition.txt");
	if (!infile) std::cerr << "RangedDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading ranged definitions..." << std::endl;

	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int _id, _type, temp;
		std::vector<int> _ammo;

		iss >> _id >> _type;

		while (iss >> temp)
			_ammo.push_back(temp);

		rangedDefinition.push_back(new RangedDefinition(_id, _type != 0, _ammo));
		_ammo.clear();
	}

	infile.close();
	std::cout << "Ranged definitions loaded: " << rangedDefinition.size() << std::endl;
}

void DefinitionLoader::loadWeaponDefinition()
{
	std::ifstream infile("WeaponDefinition.txt");
	if (!infile) std::cerr << "WeaponDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading weapon definitions..." << std::endl;

	int _id, _is2h, _speed;

	while (infile >> _id >> _is2h >> _speed)
	{
		weaponDefinition.push_back(new WeaponDefinition(_id, _is2h != 0, _speed));
	}

	infile.close();
	std::cout << "Weapon definitions loaded: " << weaponDefinition.size() << std::endl;
}

void DefinitionLoader::loadNpcDefinition()
{
	std::ifstream infile("NpcDefinition.txt");
	if (!infile) std::cerr << "NpcDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading npc definitions..." << std::endl;

	int _id,  _level, _hitpoints, _maxHit, _weakness, _attackStyle, _attackSpeed, _attackStat, _defenseStat;
	std::string _name;

	while (infile >> _id >> _name >> _level >> _hitpoints >> _maxHit >> _weakness >> _attackStyle >> _attackSpeed >> _attackStat >> _defenseStat)
	{
		npcDefinition.push_back(new NpcDefinition(_id, _name, _level, _hitpoints, _maxHit, _weakness, _attackStyle, _attackSpeed, _attackStat, _defenseStat));
	}

	infile.close();
	std::cout << "Npc definitions loaded: " << npcDefinition.size() << std::endl;
}

void DefinitionLoader::loadLootDefinition()
{
	std::ifstream infile("lootDefinition.txt");

	std::string line;
	std::vector<DropDefinition*> loot;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int id, chance, min, max, npc;
		char delim = ':';

		iss >> npc;

		while (iss >> id >> delim >> chance >> min >> delim >> max)
			loot.push_back(new DropDefinition(id, chance, min, max));

		lootDefinition.push_back(new LootDefinition(npc, loot));
		loot.clear();
	}

	infile.close();
}

void DefinitionLoader::loadShopDefinition()
{
	std::ifstream infile("shopDefinition.txt");
	if (!infile) std::cerr << "shopDefinition.txt could not be opened!" << std::endl;
	else std::cout << "Loading shop definitions..." << std::endl;

	std::string line;
	std::vector<Item> stock;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int id, amount;
		std::string name;
		iss >> name;

		while (iss >> id >> amount)
			stock.push_back(Item(id, amount));

		shopDefinition.push_back(new ShopDefinition(name, stock));
		stock.clear();
	}

	infile.close();
	std::cout << "Shop definitions loaded: " << shopDefinition.size() << std::endl;
}

void DefinitionLoader::loadDefinitions()
{
	clock_t begin = clock();
	std::cout << "Loading game defitions..." << std::endl;
	loadItemDefinition();
	loadItemBonusDefinition();
	loadEquipmentDefinition();
	loadFoodDefinition();
	loadPotionDefinition();
	loadRangedDefinition();
	loadWeaponDefinition();
	loadNpcDefinition();
	loadLootDefinition();
	loadShopDefinition();
	std::cout << "Game defitions loaded!" << std::endl;
	clock_t end = clock();
	std::cout << "Elapsed time: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

DefinitionLoader definitionLoader;