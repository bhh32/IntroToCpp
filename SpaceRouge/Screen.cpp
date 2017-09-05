#include "Screen.h"
#include <Windows.h>
#include <chrono>
#include<cassert>

using namespace std::chrono;

HANDLE buffers[2];
int writeBuffer;
unsigned long long previousTime;
bool isInit = false;

void ScreenInit()
{
	assert(!isInit && "ScreenInit should only be called once!");

	isInit = true;

	for (int i = 0; i < 2; ++i)
		buffers[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleActiveScreenBuffer(buffers[1]);

	writeBuffer = 0;

	previousTime = system_clock::now().time_since_epoch() / milliseconds(1);
}

void BufferFlip()
{
	assert(isInit && "rtc_init must be initialized.");

	SetConsoleActiveScreenBuffer(buffers[writeBuffer]);
	writeBuffer = 1 - writeBuffer;
}

bool GetKeyPress(char key)
{
	assert(isInit && "rtc_init must be initialized.");
	return GetAsyncKeyState(key);
}

void SetChar(int x, int y, char c, short foreColor, short backColor)
{
	assert(isInit && "rtc_init must be initialized.");

	CHAR_INFO chi;
	chi.Char.AsciiChar = c;
	chi.Attributes = foreColor | (backColor << 4);

	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + 1;
	rect.Top = y;
	rect.Bottom = y + 1;

	WriteConsoleOutputA(buffers[writeBuffer], &chi, { 1,1 }, { 0,0 }, &rect);
}

void SetString(int x, int y, const char string[], short foreColor, short backColor)
{
	assert(isInit && "rtc_init must be initialized.");

	CHAR_INFO chi[80];
	short len = strlen(string);
	for (int i = 0; i < len && i < 80; ++i)
	{
		chi[i].Char.AsciiChar = string[i];
		chi[i].Attributes = foreColor | (backColor << 4);
	}

	SMALL_RECT rect;
	rect.Left = x;
	rect.Right = x + len;
	rect.Top = y;
	rect.Bottom = y + 1;

	WriteConsoleOutputA(buffers[writeBuffer], chi, { len,1 }, { 0,0 }, &rect);
}

void ScreenClear(short color)
{
	assert(isInit && "rtc_init must be initialized.");

	CHAR_INFO chi[300* 255];
	CHAR_INFO dup;
	dup.Char.AsciiChar = ' ';
	dup.Attributes = color << 4;

	for (int i = 0; i < 300 * 250; ++i)
		chi[i] = dup;

	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = 300;
	rect.Top = 0;
	rect.Bottom = 250;

	WriteConsoleOutputA(buffers[writeBuffer], chi, { 300,250 }, { 0,0 }, &rect);
}

int DeltaTime()
{
	assert(isInit && "rtc_init must be initialized.");
	unsigned long long current = system_clock::now().time_since_epoch() / milliseconds(1);
	unsigned long long  deltaTime = current - previousTime;
	previousTime = current;

	return deltaTime;
}