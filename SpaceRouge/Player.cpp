#include "Player.h"
#include "Console.h"
#include <iostream>
#include <Windows.h>


//void PlayerMoveRight(int &playerX, int &mapX)
//{
//	if (playerX != mapX - 2)
//		playerX++;
//}
//
//void PlayerMoveLeft(int &playerX, int &mapX)
//{
//	if (playerX != 1)
//		playerX--;
//}
//
//void PlayerShoot(int &playerX, int &mapY, bool &hasShot, int &shotY, int &shotX)
//{
//	hasShot = true;
//	shotY = mapY - 4;
//	shotX = playerX;		
//}



void Draw(Player p)
{
	int trail = p.trail;
	SetString(p.x + 2, p.y - 2, "^", BLACK, WHITE);
	SetString(p.x + 2, p.y - 1, "|", BLACK, WHITE);
	SetString(p.x, p.y,        "/|\\", BLACK, WHITE);

	if (p.thrusting)
		SetString(p.x + 2, p.y + 1, trail % 2 ? "M" : "S", BLACK, WHITE);
}

void Update(Player &p, float dt)
{
	p.thrusting = GetAsyncKeyState(VK_UP);
	p.trail += dt * 10;
	p.x += (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) * dt * p.speedX;
	p.x -= (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) * dt * p.speedX;
	p.y += (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) * dt * p.speedY;
	p.y -= (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) * dt * p.speedY;
}