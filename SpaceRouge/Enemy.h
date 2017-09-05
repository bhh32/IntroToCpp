#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

struct Enemy
{
	int x, y;
	float speedX, speedY;
};

void DrawEnemy(Enemy &enemy, char newEnemy[]);
void UpdateEnemy(Enemy &enemy, Player player, char newEnemy[], float deltaTime);

#endif ENEMY_H