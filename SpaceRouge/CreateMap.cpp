#include "CreateMap.h"
#include <iostream>

void Map::DrawMap()
{
	mapY = 100; // Rows
	mapX = 80; // Columns

	mapArray[mapY][mapX];

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

	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			std::cout << mapArray[i][j];
		}
		std::cout << "\n";
	}
	

	system("pause");
}