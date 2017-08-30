#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h> // Needed to pass the handle for other classes

#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_MAGENTA 5
#define DARK_YELLOW 6

#define LIGHT_GREY 7
#define DARK_GREY 8

#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_YELLOW 14
#define WHITE 15

class Console
{
public:
	HANDLE outHandle;
	HANDLE inHandle;
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD screenSize;
	char title[80];


	// functions
	bool GetKey(char key);
	void PutChar(int x, int y, char c, short foreColor, short backColor);

	void Clear(short color);

	void StrToCHI(char string[], size_t bSize, CHAR_INFO[]);

	void CreateConsole(HANDLE &outHandle, HANDLE &inHandle, CONSOLE_CURSOR_INFO &cursorInfo, COORD &screenSize, char title[]);
};
#endif CONSOLE_H