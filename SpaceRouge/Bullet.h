#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "Player.h"

struct Bullet
{
	float lifeTime;
	float x;
	float y;
	float speed;
	bool beenshot;
	bool intShot;

};

// Updates the bullet movement
void UpdateBullet(Bullet &bullet, Player & player, float deltaTime);

// Draws the bullet
void DrawBullet(Bullet &currentBullet);

// Intializes the bullet object
void InitBullet(Bullet &currentBullet, Player &player);

#endif BULLET_H