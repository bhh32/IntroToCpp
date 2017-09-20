#include <Windows.h>
#include <string>
#include "Screen.h"
#include "Player.h"
#include "Bullet.h"

void InitPlayer(Player &player)
{
	player.x = 70;
	player.y = 65;
	player.speedX = 40;
	player.speedY = 20;
	player.hp = 5;
	player.score = 0;
	player.trail = 0;
	player.shotInitLife = 20;
	player.isDead = false;
	player.pickupCollide = false;
	player.fireRate = 0;
	player.firedShot = false;
	player.fireDelay = .25f;
	player.fireTimer = -1;
	player.altFire = -1;
}

// Draw the player in it's updated position
void DrawPlayer(Player &player)
{
	if (!player.isDead)
	{
		// Sets the players thrusting trail
		int trail = player.trail;

		// Draws the Player Ship
		SetString(player.x + 2, player.y - 2, "u", LIGHT_CYAN, BLACK);
		SetString(player.x + 2, player.y - 1, "|", LIGHT_CYAN, BLACK);
		SetString(player.x, player.y, "|-|-|", LIGHT_CYAN, BLACK);

		// Test if the player is moving forward (up)
		if (player.thrusting)
			// Draws the thrusting trail characters
			SetString(player.x + 2, player.y + 1, trail % 2 ? "^" : "s", WHITE, BLACK);
	}
	else
		return;
}

void DrawScore(Player &player, MainGameLoop &gameLoop)
{
	char score[80] = { "Score: \0" };
	
	std::string playerScoreString = std::to_string(player.score);
	
	SetString(130, 1, score, LIGHT_YELLOW, BLACK);
	SetString(137, 1, playerScoreString, LIGHT_YELLOW, BLACK);
}

void DrawHP(Player &player)
{
	// Create a char array to hold the lives
	char playerHealth[2];

	// Define the elements
	for (int i = 0; i < 2; ++i)
	{
		playerHealth[i] = { 0 };
	}

	// Sets the number to the correct number ascii character
	playerHealth[0] = (char)player.hp + 48;

	// Draws the Lives string
	SetString(2, 1, "Lives: ", LIGHT_RED, BLACK);
	
	// Draws the actual number of lives
	SetString(9, 1, playerHealth, LIGHT_RED, BLACK);
}

// Updates the player
void UpdatePlayer(Player &player, float deltaTime, MainGameLoop &gameLoop)
{
	if (!player.isDead)
	{
		// Sets the bullets' intial lifetime
		float bulletInitLife = 2000;

		// Plays the thrusting 'animation' if the player is going forward
		player.thrusting = GetKeyPress('W');
		if (!GetKeyPress('W'))
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

		if (GetKeyPress(VK_ESCAPE) != 0)
		{
			gameLoop.playerQuit = true;
			gameLoop.gameOver = true;
		}
	}
	
	if (player.hp <= 0)
	{
		gameLoop.playerLose = true;
		gameLoop.gameOver = true;
	}
}

int ReturnScore(int &score)
{
	return score;
}