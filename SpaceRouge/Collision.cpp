#include "Collision.h"

// Returns if there was a collision between an enemy and the player
bool PlayerEnemyCollision(Player &player, Enemy &enemy)
{
	float rad2 = (player.x + 2 - enemy.x)*(player.x + 2 - enemy.x) + (player.y - enemy.y)*(player.y - enemy.y);
	return rad2 < 6.0;
}

// Returns if there was a collision between an enemy and a bullet 
bool EnemyBulletCollision(Enemy &enemy, Bullet &bullet)
{
	float rad2 = (bullet.x - enemy.x)*(bullet.x - enemy.x) + (bullet.y - enemy.y)*(bullet.y - enemy.y);
	return rad2 < 2;
}

bool PlayerPickupCollision(Player &player, Pickup &pickup)
{
	float rad2 = (player.x + 2 - pickup.x) * (player.x + 2 - pickup.x) + (player.y - pickup.y) * (player.y - pickup.y);
	return rad2 < 6.0f;
}
