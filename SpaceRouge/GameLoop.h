#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H

#ifndef CONSOLE_H
#include "Console.h"
#else
#undef CONSOLE_H
#include "Console.h"
#endif CONSOLE_H

class MainGameLoop
{
public:
	// The main game loop; used to run the game to completion.
	MainGameLoop();

	// Go To Main Menu
	void MainMenu(Console handle);

	// Play The Game
	void PlayGame();

	// The main game loop destructor; unloads the game from memory before program completion.
	~MainGameLoop();

private:
	int gameSpeed = 400;
};

#endif GAMELOOP_H
