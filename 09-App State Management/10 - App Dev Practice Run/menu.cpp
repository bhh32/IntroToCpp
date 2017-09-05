#include <iostream>
#include "menu.h"
#include "gameloop.h"

using std::cin;
using std::cout;

int Menu::PlayGame()
{
	GameLoop gameLoop;
	cout << "Do you want to play 'The Legend of Kobey', go to the Credits, or Quit the game?\n {p} - Play\n {c} - Credits\n {q} - Quit ";
	cin >> playOrCredits;

	while (true)
	{
		if (playOrCredits == 'P' || playOrCredits == 'p')
		{
			gameLoop.MainGameLoop();
			PlayGame();
		}
		else if (playOrCredits == 'C' || playOrCredits == 'c')
		{
			GoToCredits();
			cout << "\n";
		}
		else if (playOrCredits == 'Q' || playOrCredits == 'q')
			return 0;
		else
			cout << "You didn't choose an applicable choice.\n Try Again!";
	}

	return 0;
}

void Menu::GoToCredits()
{
	cout << "                  CREDITS                  \n";
	cout << "-------------------------------------------\n";

	cout << "Idea:\n AIE Programming Teaching Staff: Terry, Esme, Kobey\n";
	cout << "Programming:\n Bryan Hyland\n";

	cout << "\n";
	while (!creditCheck)
	{
		cout << "To Go Back To The Main Menu Press {m}: ";
		cin >> backToMainMenu;

		if (backToMainMenu == 'm' || backToMainMenu == 'M')
		{
			creditCheck = !creditCheck;
			PlayGame();
		}
		else
		{
			cout << "You didn't enter the correct character!\n Try Again\n";
		}
	}
}