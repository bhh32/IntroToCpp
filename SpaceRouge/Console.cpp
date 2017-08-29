// Standard Libraries
#include <stdio.h>
#include <iostream>

// Cpp Header File
#include "Console.h"

void Console::CreateConsole()
{
	outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	inHandle = GetStdHandle(STD_INPUT_HANDLE);
	cursorInfo = {1, TRUE};
	screenSize = { 50, 100 };
	
	SetStdHandle(STD_OUTPUT_HANDLE, outHandle);
	SetStdHandle(STD_INPUT_HANDLE, inHandle);

	SetConsoleScreenBufferSize(outHandle, screenSize);

	SetConsoleTitle("Bryan - Space Rouge");

	SetConsoleCursorInfo(outHandle, &cursorInfo);	
}
