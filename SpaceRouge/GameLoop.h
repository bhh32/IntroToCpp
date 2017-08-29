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
	int gameSpeed = 400;
	bool consoleCreated = false;

	// The main game loop; used to run the game to completion.
	void GameLoop();

private:
	
};

#endif GAMELOOP_H
