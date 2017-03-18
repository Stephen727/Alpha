#include "Combat.h"
#include "CombatAssistant.h"
#include <iostream>
#include "FormulaData.h"
#include "MeleeFormulas.h"
#include "RangedFormulas.h"
#include "MagicFormulas.h"
#include <random>
#include <time.h>
#include "Skills.h"
#include "Equipment.h"
#include "Magic.h"
#include "PrayerBook.h"
#include "Inventory.h"
#include "UseItem.h"
#include "Slayer.h"
#include "Loot.h"
#include "Prayer.h"
#include <conio.h>


Combat::Combat()
{
	srand(time(NULL));
	playerInput = -1;
	playerHit = 0;
	npcHit = 0;
	combatInterface = new CombatInterface;
}

Combat::~Combat()
{
	delete combatInterface;
}


int Combat::meleeAttack(Player* player, Npc* npc)
{
	MeleeFormulas meleeFormulas;
	double attackRoll = meleeFormulas.getAttackRoll(*player);
	double defenseRoll = meleeFormulas.getDefenseRoll(*npc);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % (int)meleeFormulas.calculateBasedamage(*player) + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::rangedAttack(Player* player, Npc* npc)
{
	RangedFormulas rangedFormulas;
	double attackRoll = rangedFormulas.getAttackRoll(*player);
	double defenseRoll = rangedFormulas.getDefenseRoll(*npc);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % (int)rangedFormulas.calculateBasedamage(*player) + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::magicAttack(Player* player, Npc* npc)
{
	MagicFormulas magicFormulas;
	double attackRoll = magicFormulas.getAttackRoll(*player);
	double defenseRoll = magicFormulas.getDefenseRoll(*npc);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % (int)magicFormulas.calculateBasedamage(*player) + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::meleeAttack(Npc* npc, Player* player)
{
	MeleeFormulas meleeFormulas;
	double attackRoll = meleeFormulas.getAttackRoll(*npc);
	double defenseRoll = meleeFormulas.getDefenseRoll(*player);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % npc->getNpcDefinition().getMaxHit() + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::rangedAttack(Npc* npc, Player* player)
{
	RangedFormulas rangedFormulas;
	double attackRoll = rangedFormulas.getAttackRoll(*npc);
	double defenseRoll = rangedFormulas.getDefenseRoll(*player);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % npc->getNpcDefinition().getMaxHit() + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::magicAttack(Npc* npc, Player* player)
{
	MagicFormulas magicFormulas;
	double attackRoll = magicFormulas.getAttackRoll(*npc);
	double defenseRoll = magicFormulas.getDefenseRoll(*player);

	FormulaData formulaData;
	if (formulaData.isAccurateHit(attackRoll, defenseRoll))
	{
		int damage = rand() % npc->getNpcDefinition().getMaxHit() + 1;
		return damage;
	}
	else
		return 0;
}

int Combat::getMaxInput(Player* player)
{
	switch (player->getAttackStyle())
	{
	case 0:
		return 4;
		break;
	case 1:
		return 2;
		break;
	case 2:
		return 1;
		break;
	default:
		return 4;
		break;
	}
}

bool Combat::cantAttack(Player* player, int input)
{
	if (player->getAttackStyle() == 1)
	{
		if (!player->equipment->hasAmmo())
			return true;
	}
	else if (player->getAttackStyle() == 2)
	{
		if (!player->magic->hasRunes())
			return true;
	}

	return (input < 0 || input > getMaxInput(player));
}

int Combat::getPlayerInput(Player* player)
{
	int input;

	while (!(std::cin >> input) || cantAttack(player, input))
	{
		if (!input) break;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	return input;
}

bool getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}

bool Combat::checkPlayerInput(Player* player)
{
	static bool autoAttack = false;

	char key = ' ';
	if (getInput(&key) || cantAttack(player, playerInput)) autoAttack = false;

	if (!autoAttack)
	{
		playerInput = getPlayerInput(player);
		player->setCombatStance(playerInput);
		autoAttack = true;
	}

	if (!playerInput) { autoAttack = false; return true; }
	else
		return false;
}

int Combat::getPlayerDamage(Player* player, Npc* npc)
{
	switch (player->getAttackStyle())
	{
	case 0:
		playerHit = meleeAttack(player, npc);
		break;
	case 1:
		playerHit = rangedAttack(player, npc);
		player->equipment->useAmmo();
		break;
	case 2:
		playerHit = magicAttack(player, npc);
		player->magic->castSpell();
		break;
	}

	CombatAssistant *combatAssistant = new CombatAssistant;

	if (!combatAssistant->canAttack(player, npc))
		playerHit = 0;

	playerHit = combatAssistant->playerDamageModifier(player, npc, playerHit);
	if (player->getAttackStyle() == npc->getNpcDefinition().getWeakness()) playerHit *= 1.10;
	delete combatAssistant;

	if (playerHit >= npc->getHitpoints())
		if (combatAssistant->canKill(player, npc))
		{
			playerHit = npc->getHitpoints();
			player->slayer->checkKill(npc);
		}
		else
			playerHit = npc->getHitpoints() - 1;

	return playerHit;
}

int Combat::getNpcDamage(Npc* npc, Player* player)
{
	switch (npc->getNpcDefinition().getAttackStyle())
	{
	case 0:
		npcHit = meleeAttack(npc, player);
		break;
	case 1:
		npcHit = rangedAttack(npc, player);
		break;
	case 2:
		npcHit = magicAttack(npc, player);
		break;
	}

	CombatAssistant *combatAssistant = new CombatAssistant;
	npcHit = combatAssistant->npcDamageModifier(npc, player, npcHit);
	delete combatAssistant;

	if (npcHit > player->skills->getEffect(hitpoints))
		npcHit = player->skills->getEffect(hitpoints);

	return npcHit;
}

void Combat::fight(Player* player, Npc* npc)
{
	combatInterface->displayScreen(*player, *npc, playerHit, npcHit);

	while (player->skills->getEffect(hitpoints) && npc->getHitpoints())
	{
		if (checkPlayerInput(player)) { return; }

		player->setInCombat(true);

		//Player is attacking npc
		if (!player->getCombatDelay())
		{
			playerHit = getPlayerDamage(player, npc);

			npc->subHitpoints(playerHit);

			if (npc->getId() != 121)
				player->skills->addCombatExperience(playerHit);

			system("CLS");
			combatInterface->displayScreen(*player, *npc, playerHit, npcHit);
		}

		//Npc is attacking player
		if (!npc->getDelay())
		{
			npcHit = getNpcDamage(npc, player);
			player->skills->subHitpoints(npcHit);

			system("CLS");
			combatInterface->displayScreen(*player, *npc, playerHit, npcHit);
		}

		_sleep(600);
		player->tickDelay();
		npc->tickDelay();
		player->skills->update();
	}
	player->setInCombat(false);
}

void Combat::getLoot(Player* player, int id, Ground* ground)
{
	Loot *loot = new Loot(id);
	std::vector<Item*> drop = loot->getDrop();

	if (drop.size())
	{
		for (auto i : drop)
		{
			if (player->prayer->boneCrusher(i))
				;
			else if (player->inventory->canAdd(*i))
				player->inventory->add(new Item(i->getId(), i->getAmount()));
			else
				ground->drop(i);
		}
		delete loot;
	}
}

void Combat::battle(Player* player, int id)
{
	char select = ' ';
	int input;
	Ground *ground = new Ground(player);

	while (player->skills->getEffect(hitpoints))
	{
		Npc *npc = new Npc(id);

		while (player->skills->getEffect(hitpoints) && npc->getHitpoints())
		{
			combatInterface->displayMenu(*player, *npc, playerHit, npcHit);

			select = _getch();
			select = toupper(select);

			switch (select)
			{
			case 'Q':
				fight(player, npc);
				resetPlayerInput();
				break;
			case 'S':
				do
				{
					player->skills->displayStats();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
				} while (input);
				break;
			case 'B':
				do
				{
					player->inventory->displayInv();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
					if (input)
						player->useItem->select(input - 1);
				} while (input);
				break;
			case 'G':
				do
				{
					player->equipment->displayEquip();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
					player->equipment->unequip(input - 1);
				} while (input);
				break;
			case 'W':
				do
				{
					player->prayerBook->displayPrayerBook();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
					player->prayerBook->toggle(input - 1);
				} while (input);
				break;
			case 'E':
				do
				{
					player->magic->displaySpellBook();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
					player->magic->setCurrentSpell(input - 1);
				} while (input);
				break;
			case 'R':
				do
				{
					ground->display();
					while (!(std::cin >> input))
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
						}
					}
					ground->pickup(input - 1);
				} while (input);
				break;
			case '0':
				player->resetDelay();
				player->setInCombat(false);
				delete npc;
				delete ground;
				return;
				break;
			default:
				break;
			}
		}
		if(!npc->getHitpoints()) getLoot(player, id, ground);
		player->resetDelay();
		delete npc;
	}
	if (!player->skills->getEffect(hitpoints))
		player->respawn();
	delete ground;
}

void Combat::battle(Player* player, Npc* npc)
{
	char select = ' ';
	int input;
	Ground *ground = new Ground(player);

	while (player->skills->getEffect(hitpoints) && npc->getHitpoints())
	{
		combatInterface->displayMenu(*player, *npc, playerHit, npcHit);

		select = _getch();
		select = toupper(select);

		switch (select)
		{
		case 'Q':
			fight(player, npc);
			resetPlayerInput();
			break;
		case 'S':
			do
			{
				player->skills->displayStats();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
			} while (input);
			break;
		case 'B':
			do
			{
				player->inventory->displayInv();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				if (input)
					player->useItem->select(input - 1);
			} while (input);
			break;
		case 'G':
			do
			{
				player->equipment->displayEquip();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				player->equipment->unequip(input - 1);
			} while (input);
			break;
		case 'W':
			do
			{
				player->prayerBook->displayPrayerBook();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				player->prayerBook->toggle(input - 1);
			} while (input);
			break;
		case 'E':
			do
			{
				player->magic->displaySpellBook();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				player->magic->setCurrentSpell(input - 1);
			} while (input);
			break;
		case 'R':
			do
			{
				ground->display();
				while (!(std::cin >> input))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				ground->pickup(input - 1);
			} while (input);
			break;
		case '0':
			std::cout << "Type '0' again to exit the battle: ";
			select = ' ';
			select = _getch();
			select = toupper(select);
			if (select == '0')
			{
				player->resetDelay();
				player->setInCombat(false);
				delete ground;
				return;
			}	
			break;
		default:
			break;
		}
	}
	player->setInCombat(false);
	
	if (!npc->getHitpoints()) getLoot(player, npc->getId(), ground);
	
	player->resetDelay();
	
	if (!player->skills->getEffect(hitpoints))
		player->respawn();
	
	delete ground;
}