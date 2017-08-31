#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h> // Needed to pass the handle for other classes


/*
The following definitions can be used in place of the color you want to use.
*/
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

/*
Must be called before any of the other functions.
Sets up the console rendering context assuming an 80x25 console area.
If you want to change the size, you will need to modify the source.
*/
void ConsoleInit();

/*
Call once at the beginning of the game loop. This flips the rendering
buffer which eliminates screen flicker.
*/
void FlipBuffers();

// Fetch the key without stopping the program
//bool rtc_get_key(char key);

// Write a character to an X, Y
void SetChar(int x, int y, char c, short foreColor, short backColor);

// Write a strng to an X, Y
void SetString(int x, int y, const char string[], short foreColor, short backColor);

// Clear the screen to a background color
void ClearScreen(short color);

// Fetch delta time in milliseconds (int)
// Delta time is updated each time this is called, so you should call it
// once at the beginning of each update!
int DeltaTime();

//class Console
//{
//public:
//	/*HANDLE outHandle;
//	HANDLE inHandle;
//	CONSOLE_CURSOR_INFO cursorInfo;
//	COORD screenSize;
//	char title[80];*/
//
//
//	// functions
//	/*bool GetKey(char key);
//	void PutChar(int x, int y, char c, short foreColor, short backColor);
//
//	void Clear(short color);
//
//	void StrToCHI(char string[], size_t bSize, CHAR_INFO[]);
//
//	void CreateConsole(HANDLE &outHandle, HANDLE &inHandle, CONSOLE_CURSOR_INFO &cursorInfo, COORD &screenSize, char title[]);*/
//};
#endif CONSOLE_H