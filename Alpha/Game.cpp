#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Tutorial.h"

#include <fstream>
#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}


void Game::play()
{
	Player *player = new Player;
	int input;
	std::ifstream myfile("save.txt");

	if (myfile.is_open())
	{
		myfile.close();
		player->load();
	}
	else
	{
		system("CLS");
		std::cout << "  ---Welcome---" << std::endl;
		std::cout << "Would you like to play through the tutorial?" << std::endl;
		std::cout << " [1] Yes" << std::endl;
		std::cout << " [2] No" << std::endl;
		std::cout << std::endl << ">";

		while (!(std::cin >> input) || (input < 0 || input > 2))
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}

		if (input == 0)
			return;
		else if (input == 1)
		{
			Tutorial *tutorial = new Tutorial;
			player = tutorial->run();
			delete tutorial;
		}
		else if (input == 2)
			player->create();
	}

	Map *map = new Map(player);
	map->display();

	delete map;
	delete player;
}