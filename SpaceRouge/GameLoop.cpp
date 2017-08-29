#include <iostream>
#include "GameLoop.h"
#include "Console.h"
#include "MainMenu.h"
#include "Player.h"


// The main game loop; calls the menu system, which leads to the PlayGame function
void MainGameLoop::GameLoop()
{
	// Initialize the console parameters
	Console console =
	{
		GetStdHandle(STD_OUTPUT_HANDLE), GetStdHandle(STD_INPUT_HANDLE),
		{ 1, TRUE },{ 50, 100 }, "Bryan - Space Rouge"
	};
		// Create the console with parameters above
		CreateConsole(console.outHandle, console.inHandle, console.cursorInfo, console.screenSize, console.title);
		
		// Set consoleCreated to true
		consoleCreated = !consoleCreated;

		// Open the main menu
		MainMenu menus;
		menus.Menus(console);

	system("pause");
}