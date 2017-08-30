#pragma once
#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	int playerX;
	int playerY;
	int lives;
	bool isPowerUp;

	void SetPlayerStats();
};



#endif PLAYER_H