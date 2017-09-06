#include <iostream>
#include <Windows.h>
#include "main.h"
#include "GameLoop.h"

using std::cout;
using std::cin;

int main(void)
{
	choiceMade = false;
	char playerInput = ' ';

	MainGameLoop gameLoop;
	gameLoop.gameOver = false;
	gameLoop.playerLose = false;
	gameLoop.playerQuit = false;
	gameLoop.playerWin = false;
	gameLoop.playerScore = 0;

	while (true)
	{
		system("cls");

		if (gameLoop.playerWin)
		{
			WinScreen();
		}
		else if (gameLoop.playerLose)
		{
			LoseScreen(gameLoop);
		}
		else if (gameLoop.playerQuit)
		{
			system("cls");
			QuitScreen();
		}
		else
		{
			char yesNo;
			while (!choiceMade)
			{
				cout << "                                                         Welcome to Bryan: Space Rouge!\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";

				cout << "Would you like to play the game, quit, or go to the credits? {p}/{q}/{c}: ";
				cin >> yesNo;

				if (yesNo == 'p' || yesNo == 'P')
				{
					cout << "                                                                Have Fun!\n";
					choiceMade = true;
					Sleep(500);
					GameLoop(gameLoop);
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
					Sleep(500);
					system("cls");
				}
			}

			
			yesNo = ' ';
			choiceMade = false;
		}
	}
}

void Credits()
{
	system("cls");
	char userInput;
	cout << "\n";
	cout << "\n";
	cout << "                                                                                  CREDITS\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                                                                    Idea and Programming: Bryan Hyland\n";
	cout << "                                                                    Programming/Advisory: Esme\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "Press {m} to return to the Main Menu: ";
	while (true)
	{
		cin >> userInput;

		if (userInput == 'm' || userInput == 'M')
		{
			system("cls");
			break;
		}
		else
			cout << "You didn't choose a valid choice. Try again: ";
	}

}

void WinScreen()
{
	cout << "                                                                                 YOU WIN!\n";
	cout << "                                                                                 GREAT JOB!\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

	cout << "Press any key to return to the Main Menu... ";
	getchar();
}

void LoseScreen(MainGameLoop &gameLoop)
{
	cout << "                                                                                YOU LOSE!\n";
	cout << "                                                                                TRY AGAIN!\n";
	cout << "                                                                                Score: " << gameLoop.playerScore << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

	cout << "Press any key to return to the Main Menu... ";
	getchar();
}

void QuitScreen()
{
	system("cls");
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                                                                              Sorry To See You Go!\n";
	Sleep(500);
	exit(0);
}