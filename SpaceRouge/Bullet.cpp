#include "Bullet.h"
#include "Screen.h"
#include "Player.h"

// Updates the bullets as they fly
void UpdateBullet(Bullet &bullet, float deltaTime)
{
	// Checks to see if the bullet isn't dead
	if (bullet.lifeTime >= 0)
	{
		// Makes the bullet fly from the player to the top of the screen
		bullet.y -= deltaTime * bullet.speed;
	}

	// Decreases the lifetime by delta time
	bullet.lifeTime -= deltaTime;
}

// Intializes the bullet information
void InitBullet(Bullet &currentBullet, Player &player)
{
	currentBullet.lifeTime = 4;
	currentBullet.x = player.x + 2 + 2 * player.altFire;
	currentBullet.y = player.y;
	currentBullet.intShot = false;
	currentBullet.beenshot = true;
	currentBullet.speed = 10;
}

// Draws the bullet
void DrawBullet(Bullet &currentBullet)
{
	// Ensures the bullet isn't dead when it's drawn
	if (currentBullet.lifeTime >= 0)
		// Draws the bullet in the updated position
		SetChar(currentBullet.x, currentBullet.y, '|', WHITE, BLACK);
}