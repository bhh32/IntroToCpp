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

void UpdateBullet(Bullet bullet, float deltaTime);
void DrawBullet(Bullet bullet[], Bullet &currentBullet, Player &player);

#endif BULLET_H