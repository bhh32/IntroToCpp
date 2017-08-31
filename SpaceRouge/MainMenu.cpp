#include <iostream>
#include "MainMenu.h"
#include "GameLoop.h"
#include "Console.h"
#include "GameLoop.h"
#include "Level1.h"
#include "Player.h"
#include "Bullet.h"

// Goes to the main menu
void MainMenu::Menus()
{
	// Create a gameloop object
	MainGameLoop gameLoop;

	// Intialize the menuCheck bool
	menuCheck = false;

	//// Create a position COORD, and set the cursor to that position
	//COORD pos = { 15, 10 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	
	std::cout << "Do you want to Play, go to the Credits, or Quit the game?\n {p} - Play\n {c} - Credits\n {q} - Quit " << std::endl;
	
	// Take in the user's input
	playOrCredits = getchar();

	// while the menuCheck is false check to see what the player wants to do.
	while (!menuCheck)
	{
		

		// checks to see if the player wants to play the game
		if (playOrCredits == 'P' || playOrCredits == 'p')
		{
			menuCheck = !menuCheck;
			PlayGame();
		}
		// checks to see if the player wants to see the credits
		else if (playOrCredits == 'C' || playOrCredits == 'c')
		{
			GoToCredits();
			std::cout << "\n";
		}
		// checks to see if the player wants to quit the game
		else if (playOrCredits == 'Q' || playOrCredits == 'q')
			break;
		// have the user put something valid into the input
		else
			std::cout << "You didn't choose an applicable choice.\n Try Again!";
	}
}

void MainMenu::PlayGame()
{


//	Map map;
//	int mapX = 40;
//	int mapY = 45;
//	
//	int playerX = mapX / 2;
//	int shotX = playerX;
//	int shotY = 100;
//
//	Player player =
//	{
//		playerX, 3, false, false
//	};
//
//	while (true)
//	{		
//
//		map.DrawMap(mapX, mapY, playerX, player.hasShot, shotX, shotY);
//
//		if (GetAsyncKeyState(VK_RIGHT) != 0)
//			PlayerMoveRight(playerX, mapX);
//		else if (GetAsyncKeyState(VK_LEFT) != 0)
//			PlayerMoveLeft(playerX, mapX);
//		else if (GetAsyncKeyState(VK_UP) != 0)
//			PlayerShoot(playerX, mapY, player.hasShot, shotY, shotX);
//
//		// Quit
//		else if (GetAsyncKeyState(VK_ESCAPE) != 0)
//		{
//			console.Clear(BLACK);
//			Menus(console);
//			break;
//		}		
//		
//		BulletUpdate(player.hasShot, shotY);
//		console.Clear(BLACK);
//	}
}

// Goes to the credits screen
void MainMenu::GoToCredits()
{
	HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetStdHandle(STD_OUTPUT_HANDLE, outHandle);

	// Center Credits
	COORD centerPos = { 30, 2 };
	SetConsoleCursorPosition(outHandle, centerPos);
	std::cout << "                  CREDITS                    ";
	
	// Center Break Line
	centerPos = { 1, 3 };
	SetConsoleCursorPosition(outHandle, centerPos);
	std::cout << "--------------------------------------------------------------------------------------------------\n";

	// Center Credits Line
	centerPos = { 35, 15 };
	SetConsoleCursorPosition(outHandle, centerPos);
	std::cout << "Programming And Idea: Bryan Hyland\n";

	std::cout << "\n";

	// Runs until the user inputs an option
	while (!creditCheck)
	{
		centerPos = { 14, 28 };
		SetConsoleCursorPosition(outHandle, centerPos);
		std::cout << "To Go Back To The Main Menu Press {m}: ";
		std::cin >> backToMainMenu;
		
		if (backToMainMenu == 'm' || backToMainMenu == 'M')
		{
			creditCheck = !creditCheck;
			system("cls");
			SetConsoleCursorPosition(outHandle, centerPos);
			Menus();
		}
		else
		{
			std::cout << "You didn't enter the correct character!\n Try Again\n";
		}
	}
}

