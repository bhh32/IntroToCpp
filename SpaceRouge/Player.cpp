#include "Player.h"
#include <iostream>
#include <Windows.h>


void PlayerMoveRight(int &playerX, int &mapX)
{
	if (playerX != mapX - 2)
		playerX++;
}

void PlayerMoveLeft(int &playerX, int &mapX)
{
	if (playerX != 1)
		playerX--;
}

void PlayerShoot(int &playerX, int &mapY, bool &hasShot, int &shotY, int &shotX)
{
	hasShot = true;
	shotY = mapY - 4;
	shotX = playerX;		
}