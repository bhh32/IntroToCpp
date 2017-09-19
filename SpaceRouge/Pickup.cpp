#include <random>
#include "Pickup.h"
#include "Screen.h"

// Draws the pickup
void DrawPickup(Pickup &pickup)
{
	SetChar(pickup.x, pickup.y, '$', WHITE, BLACK);
}

// Updates the pickup position
void UpdatePickup(Pickup &pickup, float deltaTime)
{
	// Checks to see if the pickup is in the operating range, if it isn't it flips direction
	if (pickup.x < (pickup.startX - pickup.opRange))
		pickup.velX = 1;

	// Checks to see if th pickup is in the operating range, if it isn't it flips direction
	if (pickup.x > (pickup.startX + pickup.opRange))
		pickup.velX = -1;

	// Moves the pickup on the x and y axis
	pickup.x += pickup.velX * pickup.speedX * deltaTime;
	pickup.y += pickup.speedY * deltaTime;

	// Kills the pickup if it goes off screen
	if (pickup.y > 100) // SCREEN HEIGHT
		pickup.isPickedUp = true;
}

// Initializes the pickup objects
void InitPickup(Pickup &pickup)
{
	pickup.isPickedUp = false;
	pickup.opRange = rand() % 10;
	pickup.x = rand() % 100;
	pickup.y = 0;
	pickup.startX = pickup.x;
	pickup.velX = -1;
	pickup.speedX = 20;
	pickup.speedY = 4;
}