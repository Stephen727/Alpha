#include "Player.h"
#include "Combat.h"
#include "Bank.h"
#include "Shop.h"

int main()
{
	Player *player = new Player("Reginald");

	Shop *shop = new Shop(0);
	shop->enter(player);
	delete shop;

	player->bank->access();

	Combat *combat = new Combat;
	combat->battle(player, 44);

	delete combat;
	delete player;
	
	/*
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                                                    |                        |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << "| [1] Lumbridge                                      | [Q] Shops  | [R] Bank  |" << std::endl;
	std::cout << "| [2] Varrock                                        | [W] World  | [D] Anvil |" << std::endl;
	std::cout << "| [3] Falador                                        | [E] Temple | [F] Range |" << std::endl;
	std::cout << "| [4] Seers' Village                                 |------------|-----------|" << std::endl;
	std::cout << "| [5] Ardougne                                       | [G] Gear   | [B] Bag   |" << std::endl;
	std::cout << "| [6] Karamja                                        | [S] Save   | [0] Exit  |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
	std::cout << ">";
	std::cin.ignore();
	*/

	return 0;
}