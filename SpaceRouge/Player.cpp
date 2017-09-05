#include <Windows.h>
#include "Screen.h"
#include "Player.h"
#include "Bullet.h"

void DrawPlayer(Player player)
{
	int trail = player.trail;
	SetString(player.x + 2, player.y - 2, "u", WHITE, BLACK);
	SetString(player.x + 2, player.y - 1, "|", WHITE, BLACK);
	SetString(player.x, player.y, "|-|-|", WHITE, BLACK);

	if (player.thrusting)
		SetString(player.x + 2, player.y + 1, trail % 2 ? "^" : "s", WHITE, BLACK);
}

void UpdatePlayer(Player &player, float deltaTime)
{
	float bulletInitLife = 2000;

	player.thrusting = GetKeyPress('W');
	if(!GetKeyPress('W'))
		player.thrusting = GetKeyPress(VK_UP);

	player.trail += deltaTime * 10;

	
	player.x += GetKeyPress('D') * deltaTime * player.speedX;
	if (!GetKeyPress('D'))
		player.x += GetKeyPress(VK_RIGHT) * deltaTime * player.speedX;

	player.x -= GetKeyPress('A') * deltaTime * player.speedX;
	if (!GetKeyPress('A'))
		player.x -= GetKeyPress(VK_LEFT) * deltaTime * player.speedY;

	player.y -= GetKeyPress('W') * deltaTime * player.speedY;
	if (!GetKeyPress('W'))
		player.y -= GetKeyPress(VK_UP) * deltaTime * player.speedY;

	player.y += GetKeyPress('S') * deltaTime * player.speedY;
	if (!GetKeyPress('S'))
		player.y += GetKeyPress(VK_DOWN) * deltaTime * player.speedY;

	if (GetKeyPress(VK_SPACE) != 0)
		player.firedShot = true;
}