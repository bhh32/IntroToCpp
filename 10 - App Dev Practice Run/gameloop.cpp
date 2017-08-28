#include <iostream>
#include "gameloop.h"
#include "menu.h"
#include "entities.h"

using std::cout;
using std::cin;

void GameLoop::MainGameLoop()
{
	Entities player
	{		         
		30, // hp
		30, // maxHP
		5, // attkPts
		3, // healPts
		3, // defPts
		3, // skilPtsToAdd
		0, // skillIncAmt
		'z', // skillChoice
		'z', // contOrImprove
		false, // finishedSkilUpg
		0 // actChoice
	};

	Entities chef1
	{
		10, // hp
		10, // maxHP
		5, // attkPts
		3, // healPts
		2, // defpts
		0, // skillPtsToAdd
		0, // skillIncAmt
		'z', // skillChoice
		'z', // contOrImprove
		false, // finishedSkillUpg
		0 // actChoice
	};

	while (!gameIsOver)
	{
		Battle(player, chef1);
	}

	Menu menu;
	menu.PlayGame();
}

void GameLoop::Battle(Entities &player, Entities &enemy)
{
	std::cout << "You see a chef that want's to say his donut is the Holy Donut!\nHe's Wrong! What do you want to do?\n {1} - Attack\n {2} - Defend\n {3} - Heal: ";
	
	while (!battleOver)
	{
		std::cin >> player.actionChoice;

		if (player.actionChoice == 1)
		{
			Attack(player, enemy);
		}
		else if (player.actionChoice == 2)
		{
			Defend(player, enemy);
		}
		else if (player.actionChoice == 3)
		{
			Heal(player);
		}
		else
		{
			cout << "You didn't make a correct choice!\n Try Again: \n";
		}
	}
}