#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#ifndef CONSOLE_H
#include "Console.h"
#else
#undef	CONSOLE_H
#include "Console.h"
#endif CONSOLE_H

class MainMenu
{
public:
	void Menus(Console handle);
	bool menuCheck;

protected:
	// Variables
	char playOrCredits;
	char backToMainMenu;

private:
	// Variables
	bool endGame = false;
	bool creditCheck = false;
	
	// Functions
	
	// Play The Game
	void PlayGame();

	// Go To The Credits Screen
	void GoToCredits(Console handle);
	
	
};

#endif MAINMENU_H