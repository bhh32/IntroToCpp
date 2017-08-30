// Standard Libraries
#include <stdio.h>
#include <iostream>

// Cpp Header File
#include "Console.h"

void Console::CreateConsole(HANDLE &outHandle, HANDLE &inHandle, CONSOLE_CURSOR_INFO &cursorInfo, COORD &screenSize, char title[])
{
	
	//// Set the output and input handles
	SetStdHandle(STD_OUTPUT_HANDLE, outHandle);
	SetStdHandle(STD_INPUT_HANDLE, inHandle);

	// Set the console screen buffer size
	SetConsoleScreenBufferSize(outHandle, screenSize);

	

	// Set the console title
	SetConsoleTitle(title);

	// Set the information for the console cursor
	SetConsoleCursorInfo(outHandle, &cursorInfo);

}

bool Console::GetKey(char key)
{
	return GetAsyncKeyState(key);
}

void Console::PutChar(int x, int y, char c, short foreColor, short backColor)
{
	CHAR_INFO chi;
	chi.Char.AsciiChar = c;
	chi.Attributes = foreColor | (backColor << 4);

	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + 1;
	rect.Top = y;
	rect.Bottom = y + 1;

	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), &chi, { 1,1 }, { 0,0 }, &rect);
}

void Console::Clear(short color)
{
	COORD topLeft = { 0, 0 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);

	CHAR_INFO chi[250*300];
	CHAR_INFO dup;
	dup.Char.AsciiChar = ' ';
	dup.Attributes = color << 4;

	for (int i = 0; i < 250 * 300; ++i)
		chi[i] = dup;


	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = 250;
	rect.Top = 0;
	rect.Bottom = 300;

	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), chi, { 250,300}, { 0,0 }, &rect);

	Sleep(20);

}