#include <random>
#include "Enemy.h"
#include "Screen.h"

// Draws the enemy
void DrawEnemy(Enemy &enemy)
{
	SetChar(enemy.x, enemy.y, '@', LIGHT_GREEN, BLACK );
}

// Updates the enemy position
void UpdateEnemy(Enemy &enemy, float deltaTime)
{
	// Checks to see if the enemy is in operating range, if it isn't it flips direction
	if (enemy.x < (enemy.startX - enemy.opRange))
	{
		enemy.velX = 1;
	}

	// Checks to see if the enemy is in operating range, if it isn't it flips direction
	if (enemy.x > (enemy.startX + enemy.opRange))
	{		
		enemy.velX = -1;
	}

	// Moves the enemy on the x and y axis
	enemy.x += enemy.velX * enemy.speedX * deltaTime;
	enemy.y += enemy.speedY * deltaTime;

	// Kills the enemy if it goes off screen
	if (enemy.y > 100) // SCREEN_HEIGHT
		enemy.isAlive = false;
}

// Initializes the enemy objects
void InitEnemy(Enemy &enemy)
{
	enemy.isAlive = true;
	enemy.opRange = rand() % 10;
	enemy.x = rand() % 200; // rand() % SCREEN_WIDTH
	enemy.y = 0;
	enemy.startX = enemy.x;
	enemy.velX = -1;
	enemy.speedX = 20;
	enemy.speedY = 4;
	enemy.playDeath = false;
}
