#pragma once
#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	/*int playerX;
	int lives;
	bool isPowerUp;

	bool hasShot;*/

	float x;
	float y;
	float speedX;
	float speedY;

	float trail;
	bool thrusting;
	
};

//void PlayerMoveRight(int &playerX, int &mapX);
//void PlayerMoveLeft(int &playerX, int &mapX);
//void PlayerShoot(int &playerX, int &mapY,bool &hasShot, int &shotY, int &shotX

void Draw(Player p);
void Update(Player &p, float dt);

#endif PLAYER_H