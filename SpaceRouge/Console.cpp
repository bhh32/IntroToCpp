// Standard Libraries
#include <Windows.h>
#include <chrono>
#include <cassert>

// Cpp Header File
#include "Console.h"

using namespace std::chrono;

// Creates buffer array to hold the two buffers
HANDLE buffers[2];
// Creates a write buffer variable to hold the buffer to write to
int writeBuffer;
// Creates a long long int to hold the previous time
unsigned long long previousTime;
// Creates a bool to hold whether or not the console was intialized
bool isInit = false;

// Initializes the console and it's buffers
void ConsoleInit()
{
	// Uses assert macro to ensure console isn't already intialized, otherwise the program is terminated
	assert(!isInit && "Init should only be called once!");

	// Sets isInit to true
	isInit = true;

	// Creates to buffers with the same parameters
	for (int i = 0; i < 2; i++)
		buffers[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// Sets the active screen buffer
	SetConsoleActiveScreenBuffer(buffers[1]);

	// Sets the write buffer number
	writeBuffer = 0;

	// Gets the time the console was created
	previousTime = system_clock::now().time_since_epoch() / milliseconds(1);
}

// Creates delta time
int DeltaTime()
{
	// Checks to see if the console is intialized, and if it isn't shutsdown the program.
	assert(isInit && "ConsoleInit must be initialized.");

	// Sets the current time
	unsigned long long current = system_clock::now().time_since_epoch() / milliseconds(1);
	// Sets the delta time
	unsigned long long deltaTime = current - previousTime;

	// Sets the previous time to the current time.
	previousTime = current;

	// Returns delta time
	return deltaTime;
}

// Flips the buffers back and forth to avoid screen flickering
void FlipBuffers()
{
	// Checks to see if the console is intialized, and if it isn't shutsdown the program.
	assert(isInit && "ConsoleInit must be initialized.");
	
	// Sets the active screen buffer to the one that has been written to
	SetConsoleActiveScreenBuffer(buffers[writeBuffer]);

	// Sets the write buffer to the one that is opposite of the buffer that is active 
	writeBuffer = 1 - writeBuffer;
}

// Sets the character in the position
void SetChar(int x, int y, char c, short foreColor, short backColor)
{
	// Checks to see if the console is intialized, and if it isn't shutsdown the program.
	assert(isInit && "ConsoleInit must be initialized.");

	// Creates a CHAR_INFO variable to hold the character attributes
	CHAR_INFO chi;
	// Sets the character to the ascii character
	chi.Char.AsciiChar = c;
	// Sets the fore and background color of the character
	chi.Attributes = foreColor | (backColor << 4);

	// SMALL_RECT variable to hold the screen size
	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + 1;
	rect.Top = y;
	rect.Bottom = y + 1;

	// Writes the character to the write buffer at the specified position
	WriteConsoleOutputA(buffers[writeBuffer], &chi, { 1,1 }, { 0,0 }, &rect);
}

// Writes a string out to a specified position
void SetString(int x, int y, const char string[], short foreColor, short backColor)
{
	// Checks to see if the console is intialized, and if it isn't shutsdown the program.
	assert(isInit && "ConsoleInit must be initialized.");

	// Creates a CHAR_INFO array
	CHAR_INFO chi[80];
	// Sets the string length
	short len = strlen(string);

	// Sets all of the characters to the same fore and background colors
	for (int i = 0; i < len && i < 80; ++i)
	{
		chi[i].Char.AsciiChar = string[i];
		chi[i].Attributes = foreColor | (backColor << 4);
	}

	// Creates a SMALL_RECT for the position of the string
	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + len;
	rect.Top = y;
	rect.Bottom = y + 1;

	// Writes the string to the write buffer in the specified position
	WriteConsoleOutputA(buffers[writeBuffer], chi, { len,1 }, { 0,0 }, &rect);
}

void ClearScreen(short color)
{
	assert(isInit && "ConsoleInit must be initialized.");

	CHAR_INFO chi[300 * 250];
	CHAR_INFO dup;
	dup.Char.AsciiChar = ' ';
	dup.Attributes = color << 4;

	for (int i = 0; i < 300 * 250; ++i)
		chi[i] = dup;

	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = 300;
	rect.Top = 0;
	rect.Bottom = 25;

	WriteConsoleOutputA(buffers[writeBuffer], chi, { 300, 255 }, { 0,0 }, &rect);
}

//void Console::CreateConsole(HANDLE &outHandle, HANDLE &inHandle, CONSOLE_CURSOR_INFO &cursorInfo, COORD &screenSize, char title[])
//{
//	
//	//// Set the output and input handles
//	SetStdHandle(STD_OUTPUT_HANDLE, outHandle);
//	SetStdHandle(STD_INPUT_HANDLE, inHandle);
//
//	// Set the console screen buffer size
//	SetConsoleScreenBufferSize(outHandle, screenSize);
//
//	
//
//	// Set the console title
//	SetConsoleTitle(title);
//
//	// Set the information for the console cursor
//	SetConsoleCursorInfo(outHandle, &cursorInfo);
//
//}
//
//bool Console::GetKey(char key)
//{
//	return GetAsyncKeyState(key);
//}
//
//void Console::PutChar(int x, int y, char c, short foreColor, short backColor)
//{
//	CHAR_INFO chi;
//	chi.Char.AsciiChar = c;
//	chi.Attributes = foreColor | (backColor << 4);
//
//	SMALL_RECT rect;
//	rect.Left = x;
//	rect.Right = x + 1;
//	rect.Top = y;
//	rect.Bottom = y + 1;
//
//	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), &chi, { 1,1 }, { 0,0 }, &rect);
//}
//
//void Console::Clear(short color)
//{
//	COORD topLeft = { 0, 0 };
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);
//
//	CHAR_INFO chi[250*300];
//	CHAR_INFO dup;
//	dup.Char.AsciiChar = ' ';
//	dup.Attributes = color << 4;
//
//	for (int i = 0; i < 250 * 300; ++i)
//		chi[i] = dup;
//
//
//	SMALL_RECT rect;
//	rect.Left = 0;
//	rect.Right = 250;
//	rect.Top = 0;
//	rect.Bottom = 300;
//
//	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), chi, { 250,300}, { 0,0 }, &rect);
//
//	Sleep(20);
//
//}

