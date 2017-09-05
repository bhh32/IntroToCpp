#include <iostream>
#include "main.h"
#include "GameLoop.h"
#include "Player.h"

using std::cout;
using std::cin;

int main(void)
{
	choiceMade = false;

	while (true)
	{
		MainGameLoop gameLoop;

		if (gameLoop.gameOver && gameLoop.playerWin)
		{

		}
		else if (gameLoop.gameOver && gameLoop.playerLose)
		{

		}
		else if (gameLoop.playerQuit)
		{

		}
		else
		{
			char yesNo;
			while (!choiceMade)
			{
				cout << "                            Welcome to Bryan: Space Rouge!\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";

				cout << "Would you like to play the game, quit, or go to the credits? {p}/{q}/{c}: \n";
				cin >> yesNo;

				if (yesNo == 'p' || yesNo == 'P')
				{
					cout << "                                   Have Fun!\n";
					choiceMade = true;
					_sleep(500);
				}
				else if (yesNo == 'q' || yesNo == 'Q')
				{
					QuitScreen();
				}
				else if (yesNo = 'c' || yesNo == 'C')
				{
					Credits();
				}
				else
				{
					cout << "You didn't make a valid choice, try again!\n";
					_sleep(500);
					system("cls");
				}
			}

			GameLoop(gameLoop);
		}
	}
}

void Credits()
{

}

void WinScreen(Player &player)
{

}

void LoseScreen()
{

}

void QuitScreen()
{
	cout << "               Sorry To See You Go!                   \n";
	_sleep(1050);
	system("quit");
}