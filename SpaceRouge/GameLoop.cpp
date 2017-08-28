#include <iostream>
#include "GameLoop.h"
#include "Console.h"
#include "MainMenu.h"
#include "Player.h"


// The main game loop; used to run the game to completion.
MainGameLoop::MainGameLoop()
{
	// Create The Console Window
	Console console;
	console.CreateConsole();
	MainMenu(console);

	system("pause");
}

void MainGameLoop::MainMenu(Console handle)
{
	COORD pos = { 15, 10 };
	SetConsoleCursorPosition(handle.outHandle, pos);
	MainMenu::Menus(handle);
}

void MainGameLoop::PlayGame()
{
	while (true)
	{

	}
}


// The main game loop destructor; unloads the game from memory before program completion.
MainGameLoop::~MainGameLoop()
{
	std::cout << "The Game Is Over!\n";

	system("pause");
}