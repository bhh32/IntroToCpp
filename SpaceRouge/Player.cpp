#include "Player.h"
#include <iostream>

void SetPlayerInitialPosition()
{
	Player play;
	
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			play.pos[i][j] = ' ';
		}
	}

	play.pos[25][100] = '^';

}

void GetPlayerInitialPosition()
{
	Player play;
	
	std::cout << play.pos << std::endl;
}