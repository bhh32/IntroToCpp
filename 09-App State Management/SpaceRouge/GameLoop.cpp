#include <iostream>
#include "GameLoop.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

void GameLoop()
{
	ScreenInit();

	Player player;
	player.x = 10;
	player.y = 20;
	player.speedX = 40;
	player.speedY = 20;
	player.trail = 0;
	player.shotInitLife = 20;
	player.firedShot = false;

	Enemy enemy1;
	enemy1.x = 15;
	enemy1.y = 10;
	enemy1.speedX = 40;
	enemy1.speedY = 20;
	
	char enemyArr1[6] = { ' ', '@', ' ', ' ', ' ', 0 };

	Enemy enemy2;
	enemy2.x = 25;
	enemy2.y = 8;
	enemy2.speedX = 40;
	enemy2.speedY = 20;

	char enemyArr2[6] = { ' ', ' ', '@', ' ', ' ', 0 };

	Bullet *bullets = new Bullet[50];
	for (int i = 0; i < 50; i++)
	{
		bullets[i].speed = 10;
		bullets[i].lifeTime = player.shotInitLife;
		bullets[i].beenshot = false;
	}

	Bullet currentBullet = bullets[0];

	while (true)
	{
		BufferFlip();
		float deltaTime = DeltaTime() / 1000.f;
		ScreenClear(BLACK);
		UpdatePlayer(player, deltaTime);
		UpdateEnemy(enemy1, player, enemyArr1, deltaTime);
		UpdateEnemy(enemy2, player, enemyArr2, deltaTime);
		
 		if (player.firedShot)
		{
			for (int findBullet = 0; findBullet < 0; findBullet++)
			{
				if (currentBullet.beenshot)
					currentBullet = bullets[findBullet];
				else
				{
					currentBullet.intShot = true;
					break;
				}

				if (bullets[49].beenshot)
				{
					for (int resetBullets = 0; resetBullets < 50; resetBullets++)
					{
						bullets[resetBullets].beenshot = false;
					}
				}

			}
			if (currentBullet.lifeTime < 0)
				player.firedShot = false;
		}
		DrawBullet(bullets, currentBullet, player);
		UpdateBullet(currentBullet, deltaTime);
		DrawEnemy(enemy1, enemyArr1);
		DrawEnemy(enemy2, enemyArr2);
		DrawPlayer(player);		
	}
}