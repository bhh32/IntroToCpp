#include "Bullet.h"
#include "Screen.h"
#include "Player.h"

// Updates the bullets as they fly
void UpdateBullet(Bullet &bullet, Player &player, float deltaTime)
{
	// Checks to see if the bullet isn't dead
	if (bullet.lifeTime >= 0)
	{
		if (player.pickupCollide)
		{
			player.fireRate += 2.f;
			player.pickupCollide = false;
		}

		// Makes the bullet fly from the player to the top of the screen
		bullet.y -= deltaTime * bullet.speed;	
	}

	// Decreases the lifetime b y delta time
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
	currentBullet.speed = player.fireRate + 12;

	if (currentBullet.speed > 25.0f)
		currentBullet.speed = 25.f;
}

// Draws the bullet
void DrawBullet(Bullet &currentBullet)
{
	// Ensures the bullet isn't dead when it's drawn
	if (currentBullet.lifeTime >= 0)
		// Draws the bullet in the updated position
		SetChar(currentBullet.x, currentBullet.y, '|', WHITE, BLACK);
}