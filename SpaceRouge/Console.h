#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h> // Needed to pass the handle for other classes

struct Console
{
public:
	HANDLE outHandle;
	HANDLE inHandle;
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD screenSize;

	// functions
	void CreateConsole();

};

#endif CONSOLE_H