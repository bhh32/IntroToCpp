#pragma once
#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	int PlayGame();
	

protected:
	// Variables
	char playOrCredits;
	char backToMainMenu;
	

private:
	// Variables
	bool endGame = false;
	bool creditCheck = false;
	// Functions
	void GoToCredits();
};
#endif  MENU_H