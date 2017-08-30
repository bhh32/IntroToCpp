#pragma once
#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	int playerX;
	int lives;
	bool isPowerUp;

	bool hasShot;
	
};

void PlayerMoveRight(int &playerX, int &mapX);
void PlayerMoveLeft(int &playerX, int &mapX);
void PlayerShoot(int &playerX, int &mapY,bool &hasShot, int &shotY, int &shotX);

#endif PLAYER_H