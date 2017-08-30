#include <iostream>
#include "MainMenu.h"
#include "GameLoop.h"
#include "Console.h"
#include "GameLoop.h"
#include "Level1.h"
#include "Player.h"
#include "Bullet.h"

// Goes to the main menu
void MainMenu::Menus(Console console)
{
	// Create a gameloop object
	MainGameLoop gameLoop;

	// Intialize the menuCheck bool
	menuCheck = false;

	// Create a position COORD, and set the cursor to that position
	COORD pos = { 15, 10 };
	SetConsoleCursorPosition(console.outHandle, pos);

	// Print in current console cursor position
	std::cout << "Do you want to Play, go to the Credits, or Quit the game?\n {p} - Play\n {c} - Credits\n {q} - Quit ";
	// Take in the user's input
	std::cin >> playOrCredits;

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
			GoToCredits(console);
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
	
	Console console =
	{
		GetStdHandle(STD_OUTPUT_HANDLE), GetStdHandle(STD_INPUT_HANDLE),
		{ 1, TRUE },{ 250, 300 }, "Bryan - Space Rouge"
	};

	

	console.Clear(BLACK);

	Map map;
	int mapX = 40;
	int mapY = 45;
	
	int playerX = mapX / 2;
	int shotX = playerX;
	int shotY = 100;

	Player player =
	{
		playerX, 3, false, false
	};

	while (true)
	{		

		map.DrawMap(mapX, mapY, playerX, player.hasShot, shotX, shotY);

		if (GetAsyncKeyState(VK_RIGHT) != 0)
			PlayerMoveRight(playerX, mapX);
		else if (GetAsyncKeyState(VK_LEFT) != 0)
			PlayerMoveLeft(playerX, mapX);
		else if (GetAsyncKeyState(VK_UP) != 0)
			PlayerShoot(playerX, mapY, player.hasShot, shotY, shotX);

		// Quit
		else if (GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			console.Clear(BLACK);
			Menus(console);
			break;
		}		
		
		BulletUpdate(player.hasShot, shotY);
		console.Clear(BLACK);
	}
}

// Goes to the credits screen
void MainMenu::GoToCredits(Console handle)
{
	system("cls");
	SetStdHandle(STD_OUTPUT_HANDLE, handle.outHandle);

	// Center Credits
	COORD centerPos = { 30, 2 };
	SetConsoleCursorPosition(handle.outHandle, centerPos);
	std::cout << "                  CREDITS                    ";
	
	// Center Break Line
	centerPos = { 1, 3 };
	SetConsoleCursorPosition(handle.outHandle, centerPos);
	std::cout << "--------------------------------------------------------------------------------------------------\n";

	// Center Credits Line
	centerPos = { 35, 15 };
	SetConsoleCursorPosition(handle.outHandle, centerPos);
	std::cout << "Programming And Idea: Bryan Hyland\n";

	std::cout << "\n";

	// Runs until the user inputs an option
	while (!creditCheck)
	{
		centerPos = { 14, 28 };
		SetConsoleCursorPosition(handle.outHandle, centerPos);
		std::cout << "To Go Back To The Main Menu Press {m}: ";
		std::cin >> backToMainMenu;
		
		if (backToMainMenu == 'm' || backToMainMenu == 'M')
		{
			creditCheck = !creditCheck;
			system("cls");
			SetConsoleCursorPosition(handle.outHandle, centerPos);
			Menus(handle);
		}
		else
		{
			std::cout << "You didn't enter the correct character!\n Try Again\n";
		}
	}
}

