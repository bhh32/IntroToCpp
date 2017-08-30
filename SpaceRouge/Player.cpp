#include "Player.h"
#include <iostream>

void Player::SetPlayerStats()
{
	lives = 3;
	isPowerUp = false;
	playerX = 70 / 2;
	playerY = 80 - 3;
}