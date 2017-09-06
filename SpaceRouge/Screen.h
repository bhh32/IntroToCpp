#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <Windows.h>
/*
The following defintions are to be used in the place of the colors
*/

#define BLACK		 0
#define DARK_BLUE	 1
#define DARK_GREEN	 2
#define DARK_CYAN	 3
#define DARK_RED	 4
#define DARK_MAGENTA 5
#define DARK_YELLOW	 6
#define LIGHT_GREY   7

#define DARK_GREY      8
#define LIGHT_BLUE     9
#define LIGHT_GREEN   10
#define LIGHT_CYAN    11
#define LIGHT_RED     12
#define LIGHT_MAGENTA 13
#define LIGHT_YELLOW  14
#define WHITE         15

/*
Must be called before any of the other functions.
Sets up the console rendering context assuming an 80x25 console area.
If you want to change the size, you will need to modify the source.
*/

void ScreenInit();


void ScreenBufferClear();

HANDLE GetScreenBuffer();

/*
Call once at the beginning of the game loop. This flips the rendering
buffer which eliminates screen flicker.
*/
void BufferFlip();

// Fetch the key without stopping the program
bool GetKeyPress(char key);

// Write a character to an X, Y
void SetChar(int x, int y, char c, short foreColor, short backColor);

// Write a strng to an X, Y
void SetString(int x, int y, const char string[], short foreColor, short backColor);


// Write a strng to an X, Y
void rtc_set_string_matrix(int x, int y, int w, int h, const char string[], short foreColor, short backColor);


// Clear the screen to a background color
void ScreenClear(short color);

// Fetch delta time in milliseconds (int)
// Delta time is updated each time this is called, so you should call it
// once at the beginning of each update!
int DeltaTime();

#endif SCREEN_H