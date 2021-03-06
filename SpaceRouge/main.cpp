#include <iostream>
#include <limits>
#include <Windows.h>
#include "main.h"
#include "GameLoop.h"
#include "Screen.h"

using std::cout;
using std::cin;
using std::getline;

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
	gameLoop.name = ' ';
	gameLoop.highScore1 = 0;
	gameLoop.highScore2 = 0;
	gameLoop.highScore3 = 0;

	while (true)
	{
		// Clear the screen from any previous menu
		system("cls");
		
		// If the player loses
		if (gameLoop.playerLose)
		{
			// Clear the screen
			cin.clear();
			// Call the LoseScreen Function
			LoseScreen(gameLoop);
		}
		// If the player quit
		else if (gameLoop.playerQuit)
		{
			// Clear the screen
			system("cls");
			// Call the QuitScreen Function
			QuitScreen(gameLoop);
		}
		// Draw the Main Menu and receive player input
		else
		{
			char yesNo;
			while (!choiceMade)
			{
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "                                            #######    #######   ####   ####     ####         ###      ##    ####\n";
				cout << "                                            #    ##    #    ##    ###  ###      ######        ####     ##    ####\n";
				cout << "                                            #   ##     #   ##       ####       ##    ##       ## ##    ##    ####\n";
				cout << "                                            # ##       # ##          ##       ####  ####      ##  ##   ##\n";
				cout << "                                            #  ##      #  ##         ##      ############     ##   ##  ##    ####\n";
				cout << "                                            #   ##     #   ##        ##     #####    #####    ##    ## ##    ####\n";
				cout << "                                            ######     #    ##       ##    #####      #####   ##    #####    ####\n";
				cout << "\n";
				cout << "\n";
				cout << "                     ####   ########       ####         #######     #########         #######    ########    ##      ##       #######     #########\n";
				cout << "                  ###       ##    ###     ######       ##           ##                #    ##    #      #    ##      ##      ##           ##\n";
				cout << "                 ###        ##   ###     ###  ###     ##            ##                #   ##     #      #    ##      ##     ##            ##\n";
				cout << "                   ###      ## ###      ###    ###    ##            ######            #  ##      #      #    ##      ##    ##             #####\n";
                cout << "                    ###     ####       ############   ##            ######            #  ##      #      #    ##      ##     ##   #####    #####\n";
                cout << "                  ###       ##        ###        ###   ##           ##                #   ##     #      #    ##      ##      ##     ###   ##\n";
                cout << "               ####         ##       ###          ###   #######     ##########        #    ##    ########     ########        ########    #########\n";
				cout << "\n";
				cout << "\n";

				cout << "Would you like to play the game, quit, see the high scores, or go to the credits? {p}/{q}/{h}/{c}: ";
				cin >> yesNo;

				if (yesNo == 'p' || yesNo == 'P')
				{
					yesNo = ' ';
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "                                                                       Have Fun!\n";
					choiceMade = true;
					Sleep(500);
					GameLoop(gameLoop);
					yesNo = ' ';

					/*
						The following basically turns off the double buffering to allow for normal console operation. This 
						solves the problem of screen flickering and/or nothing showing on the screen after exiting the game loop.
					*/

					// Sets the double buffer HANDLEs to NULL
					ScreenBufferClear();
					
					// Sets the new handle to the buffer handle that's currently being displayed
					HANDLE outHandle = GetScreenBuffer();

					// Deinitializes the isInit variable
					ScreenDeinit();

					// Sets the new buffer handle to a standard output console handle
					SetStdHandle(STD_OUTPUT_HANDLE, outHandle);
					
					// Sets the new buffer to be the active screen buffer
					SetConsoleActiveScreenBuffer(outHandle);

					//SaveHighScore(gameLoop, gameLoop.name);

				}
				// Player chooses to quit
				else if (yesNo == 'q' || yesNo == 'Q')
				{
					// Clear the input char
					yesNo = ' ';
					// Call the QuitScreen Function
					QuitScreen(gameLoop);
				}
				// Player chooses to see the credits
				else if (yesNo == 'c' || yesNo == 'C')
				{
					// Clears the input char
					yesNo = ' ';
					// Call the Credits Function
					Credits();
				}
				// Player Chooses to see the high scores
				else if (yesNo == 'h' || yesNo == 'H')
				{
					// Clears the input char
					yesNo = ' ';
					// Calls the HighScores Function
					HighScores(gameLoop);
				}
				// Player Didn't make a valid choice
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

// Shows the Credits of the game
void Credits()
{
	system("cls");
	char userInput;
	cout << "\n";
	cout << "\n";
	cout << "                                                                                  CREDITS\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n";
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

// Shows the game high scores
void HighScores(MainGameLoop &gameLoop)
{
	system("cls");

	char userInput;

	cout << "                                                                                 HIGH SCORES!\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

	PrintHighScore();

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

// Shows the loss screen
void LoseScreen(MainGameLoop &gameLoop)
{
	
	gameLoop.playerLose = false;
	
	char userInput;

	cout << "\n";
	cout << "\n";
	cout << "                                                                                HIGH SCORES\n";
	cout << "                                                                                 TRY AGAIN!\n";
	cout << "                                                                                Score: " << gameLoop.playerScore << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

	

	cout << "Press {m} to return to the Main Menu: ";
	
	while (true)
	{
		userInput = ' ';
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

// Shows the quit screen
void QuitScreen(MainGameLoop &gameLoop)
{
	system("cls");

	SaveHighScore(gameLoop, gameLoop.name);
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                                                                              Sorry To See You Go!\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                                                                                 High Scores!\n";
	PrintHighScore();	
	
	Sleep(3000);
	exit(0);
}