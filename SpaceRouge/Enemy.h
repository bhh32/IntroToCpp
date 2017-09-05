#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

struct Enemy
{
	float x, y;
	float speedX, speedY;
	
	int velX;
	float startX;
	float opRange;
	bool isAlive;
	bool playDeath;
};

// Draws the enemy
void DrawEnemy(Enemy &enemy);

// Updates the enemy movement
void UpdateEnemy(Enemy &enemy, float deltaTime);

// Initializes the enemy
void InitEnemy(Enemy &enemy);

#endif ENEMY_H