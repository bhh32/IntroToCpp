#include "Screen.h"
#include <chrono>
#include<cassert>

using namespace std::chrono;

// Creates 2 screen buffers to flip back and forth between
HANDLE buffers[2];
// Create variable to hold which buffer to write to
int writeBuffer;
// Holds the previous time for delta time
unsigned long long previousTime;
// Flag to see if the screen buffers are initialized
bool isInit = false;

// Initialized the screen buffers
void ScreenInit()
{
	if (isInit)
		isInit = isInit;

	// Ensures the screen buffers aren't already initalized, if they are the program quits.
	assert(!isInit && "ScreenInit should only be called once!");

	// Sets the initialization flag
	isInit = true;

	// Creates the two buffers
	for (int i = 0; i < 2; ++i)
		buffers[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// Sets the active screen buffer to the one not being written to
	SetConsoleActiveScreenBuffer(buffers[1]);

	// Sets the buffer number to write to
	writeBuffer = 0;

	// Sets the previous time from the system clock
	previousTime = system_clock::now().time_since_epoch() / milliseconds(1);
}

// Flips the screen buffers
void BufferFlip()
{
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");

	// Sets the active buffer to the buffer that was written to
	SetConsoleActiveScreenBuffer(buffers[writeBuffer]);

	// Sets the new write buffer to the opposite buffer.
	writeBuffer = 1 - writeBuffer;
}

// Wrapper function to get the key press
bool GetKeyPress(char key)
{
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");

	// Returns whether or not the key was pressed (true/false)
	return GetAsyncKeyState(key);
}

void SetChar(int x, int y, char c, short foreColor, short backColor)
{	
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");

	// Creates a CHAR_INFO variable to hold the character information
	CHAR_INFO chi;

	// Sets the character to the associated ASCII character
	chi.Char.AsciiChar = c;

	// Sets the character colors
	chi.Attributes = foreColor | (backColor << 4);

	// Creates a SMALL_RECT variables to hold the placement of the character
	SMALL_RECT rect;

	// Places the character to the coordinates given
	rect.Left = x;
	rect.Right = x + 1;
	rect.Top = y;
	rect.Bottom = y + 1;

	// Writes the character to the current write buffer in the designated position
	WriteConsoleOutputA(buffers[writeBuffer], &chi, { 1,1 }, { 0,0 }, &rect);
}

// Sets a string in a designated position
void SetString(int x, int y, const char string[], short foreColor, short backColor)
{
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");

	// Creates an array of CHAR_INFO type
	CHAR_INFO chi[80];

	// Gets the length of the string array
	short len = strlen(string);

	// Loop to set the attributes of each character in the array
	for (int i = 0; i < len && i < 80; ++i)
	{
		chi[i].Char.AsciiChar = string[i];
		chi[i].Attributes = foreColor | (backColor << 4);
	}

	// Places the string in the designated coordinates
	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + len;
	rect.Top = y;
	rect.Bottom = y + 1;

	// Writes the string to the current write buffer in the designated coordinates
	WriteConsoleOutputA(buffers[writeBuffer], chi, { len,1 }, { 0,0 }, &rect);
}

// Clears the screen
void ScreenClear(short color)
{
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");

	// Takes in the size of the screen
	CHAR_INFO chi[300* 255];

	// Place holder for the 'space' ASCII character to be written to the screen sized array
	CHAR_INFO dup;
	dup.Char.AsciiChar = ' ';
	dup.Attributes = color << 4;

	// Loops through setting the screen to 'space' characters with black backgrounds, essentially clearing the screen.
	for (int i = 0; i < 300 * 250; ++i)
		chi[i] = dup;

	// Rect holding the screen size
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = 300;
	rect.Top = 0;
	rect.Bottom = 250;

	// Writes the clearing characters to the entire screen
	WriteConsoleOutputA(buffers[writeBuffer], chi, { 300,250 }, { 0,0 }, &rect);
}

// Returns delta time
int DeltaTime()
{
	// Ensures the screen buffers are initialized, if they aren't the program quits.
	assert(isInit && "ScreenInit must be initialized.");
	
	// Sets the current system clock time
	unsigned long long current = system_clock::now().time_since_epoch() / milliseconds(1);
	
	// Calculates the delta time
	unsigned long long  deltaTime = current - previousTime;
	
	// Sets the previous time to the current time
	previousTime = current;

	// Returns the delta time
	return deltaTime;
}

// Sets the double buffers to standard buffer handles
void ScreenBufferClear()
{
	for (int i = 0; i < 2; ++i)
	{
		buffers[i] = GetStdHandle(STD_OUTPUT_HANDLE);
	}
}

// Returns the currently showing buffer handle (i.e. NOT the one currently being written to in the background).
HANDLE GetScreenBuffer()
{
	// Checks to see if the write buffer is the first element in the buffers array
	if ((buffers[writeBuffer] = buffers[0]))
		// ... if it is then the opposite element is returned as it's the current active buffer (the buffer that is showing)
		return buffers[1];
	else
		// ... if it isn't the writeBuffer element is returned as it's the current active buffer (the buffer that is showing)
		return buffers[writeBuffer];
}