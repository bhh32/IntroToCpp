// Standard Libraries
#include <stdio.h>
#include <iostream>

// Cpp Header File
#include "Console.h"

void CreateConsole(HANDLE &outHandle, HANDLE &inHandle, CONSOLE_CURSOR_INFO &cursorInfo, COORD &screenSize, char title[])
{
	// Set the output and input handles
	SetStdHandle(STD_OUTPUT_HANDLE, outHandle);
	SetStdHandle(STD_INPUT_HANDLE, inHandle);

	// Set the console screen buffer size
	SetConsoleScreenBufferSize(outHandle, screenSize);

	// Set the console title
	SetConsoleTitle(title);

	// Set the information for the console cursor
	SetConsoleCursorInfo(outHandle, &cursorInfo);	
}
