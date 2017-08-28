#include <iostream>
#include "MainMenu.h"
#include "GameLoop.h"
#include "Console.h"

void MainMenu::Menus(Console console)
{
	MainMenu mainMenu;
	std::cout << "Do you want to Play, go to the Credits, or Quit the game?\n {p} - Play\n {c} - Credits\n {q} - Quit ";
	std::cin >> mainMenu.playOrCredits;

	while (true)
	{
		if (mainMenu.playOrCredits == 'P' || mainMenu.playOrCredits == 'p')
		{
			MainGameLoop();
			Menus(console);
		}
		else if (mainMenu.playOrCredits == 'C' || mainMenu.playOrCredits == 'c')
		{
			mainMenu.GoToCredits(console);
			std::cout << "\n";
		}
		else if (mainMenu.playOrCredits == 'Q' || mainMenu.playOrCredits == 'q')
			break;
		else
			std::cout << "You didn't choose an applicable choice.\n Try Again!";
	}
}

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

