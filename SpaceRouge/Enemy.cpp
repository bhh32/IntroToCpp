#include <random>
#include "Enemy.h"
#include "Screen.h"

void DrawEnemy(Enemy &enemy, char newEnemy[])
{
	SetString(enemy.x, enemy.y, newEnemy, WHITE, BLACK);
}

void UpdateEnemy(Enemy &enemy, Player player, char newEnemy[], float deltaTime)
{
	
	if (newEnemy[0] == '@')
		newEnemy[enemy.x++];
	else if (newEnemy[enemy.x + 1] == 0)
		newEnemy[enemy.x--];
	else
		newEnemy[enemy.x++];
}