#include <Windows.h>
#include "Screen.h"
#include "Player.h"
#include "Bullet.h"

// Draw the player in it's updated position
void DrawPlayer(Player player)
{
	// Sets the players thrusting trail
	int trail = player.trail;

	// Draws the Player Ship
	SetString(player.x + 2, player.y - 2, "u", WHITE, BLACK);
	SetString(player.x + 2, player.y - 1, "|", WHITE, BLACK);
	SetString(player.x, player.y, "|-|-|", WHITE, BLACK);

	// Test if the player is moving forward (up)
	if (player.thrusting)
		// Draws the thrusting trail characters
		SetString(player.x + 2, player.y + 1, trail % 2 ? "^" : "s", WHITE, BLACK);

	if (player.isDead)
	{
		SetString(player.x + 2, player.y - 2, " ", WHITE, BLACK);
		SetString(player.x + 2, player.y - 1, " ", WHITE, BLACK);
		SetString(player.x, player.y, "     ", WHITE, BLACK);
	}
}

// Updates the player
void UpdatePlayer(Player &player, float deltaTime)
{
	// Sets the bullets' intial lifetime
	float bulletInitLife = 2000;

	// Plays the thrusting 'animation' if the player is going forward
	player.thrusting = GetKeyPress('W');
	if(!GetKeyPress('W'))
		player.thrusting = GetKeyPress(VK_UP);

	// Updates the players trail animation
	player.trail += deltaTime * 10;

	// Moves the players ship right
	player.x += GetKeyPress('D') * deltaTime * player.speedX;
	if (!GetKeyPress('D'))
		player.x += GetKeyPress(VK_RIGHT) * deltaTime * player.speedX;

	// Moves the players ship left
	player.x -= GetKeyPress('A') * deltaTime * player.speedX;
	if (!GetKeyPress('A'))
		player.x -= GetKeyPress(VK_LEFT) * deltaTime * player.speedY;

	// Moves the players ship forward (up)
	player.y -= GetKeyPress('W') * deltaTime * player.speedY;
	if (!GetKeyPress('W'))
		player.y -= GetKeyPress(VK_UP) * deltaTime * player.speedY;

	// Moves the players ship back (down)
	player.y += GetKeyPress('S') * deltaTime * player.speedY;
	if (!GetKeyPress('S'))
		player.y += GetKeyPress(VK_DOWN) * deltaTime * player.speedY;

	// Fires the players cannons
	if (GetKeyPress(VK_SPACE) != 0 && player.fireTimer < 0)
	{
		// Sets the firedShot flag to true
		player.firedShot = true;
		// Sets the fireTimer to the fireDelay
		player.fireTimer = player.fireDelay;
		// Alternates between the left and right wing cannon
		player.altFire *= -1;
	}

	// Counts down the fireTimer between each shot
	player.fireTimer -= deltaTime;
}