#include "Level1.h"
#include <Windows.h>
#include <iostream>

void Map::DrawMap(int mapX, int mapY, int playerX, bool shot, int shotx, int shoty)
{
	mapArray[mapY][mapX];
	int shotY = mapY - 2;
	int shotX = playerX;

	// Make the Right wall
	for (int i = 0; i < mapY; i++)
	{
		mapArray[i][mapX - 1] = '*';
	}

	// Make the Left wall
	for (int i = 0; i < mapY; i++)
	{
		mapArray[i][0] = '*';
	}

	// Make the body of the board
	for (int i = 1; i < mapY - 1; i++)
	{
		for (int j = 1; j < mapX - 1; j++)
		{
			mapArray[i][j] = ' ';
		}
	}

	// Make the Top
	for (int i = 1; i < mapX; i++)
	{
		mapArray[0][i] = '*';
	}

	// Make the Bottom
	for (int i = 1; i < mapX; i++)
	{
		mapArray[mapY - 1][i] = '*';
	}

	// Insert The Player 'Ship'
	mapArray[mapY - 3][playerX] = '^';

	if (shot)
	{
		mapArray[shoty][shotx] = '|';
		shot = false;
	}

	// Print out the game board array, including player and enemies
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			std::cout << mapArray[i][j];
		}
		std::cout << "\n";
	}
}


void StrToCHI(char string[], size_t bSize, CHAR_INFO outInfo[])
{
	for (int i = 0; i < strlen(string) + 1 && i < bSize; ++i)
	{
		outInfo[i].Char.AsciiChar = string[i];
		outInfo[i].Attributes = 0;
	}
}