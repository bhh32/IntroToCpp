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
	static void Menus(Console handle);


protected:
	// Variables
	char playOrCredits;
	char backToMainMenu;

private:
	// Variables
	bool endGame = false;
	bool creditCheck = false;
	// Functions
	void GoToCredits(Console handle);
};

#endif MAINMENU_H