#include <iostream>
#include<Windows.h>
#include "GameLoop.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Collision.h"
#include "Explosion.h"

void GameLoop(MainGameLoop &gameLoop)
{
	ScreenInit();

	gameLoop.gameOver = false;
	gameLoop.playerWin = false;
	gameLoop.playerLose = false;

	Player player;
	player.x = 10;
	player.y = 20;
	player.speedX = 40;
	player.speedY = 20;
	player.hp = 5;
	player.trail = 0;
	player.shotInitLife = 20;
	player.firedShot = false;
	player.fireDelay = .25f;
	player.fireTimer = -1;
	player.altFire = -1;

	Enemy *enemies = new Enemy[50];
	for (int i = 0; i < 50; ++i)
	{
		enemies[i].isAlive = false;
	}

	Bullet *bullets = new Bullet[50];
	for (int i = 0; i < 50; i++)
	{
		bullets[i].lifeTime = -1;
	}

	Explosion *explosions = new Explosion[50];
	for (int i = 0; i < 50; i++)	
		explosions[i].lifetime = -1;
	
	
	float enemyTimer = 2;
	float enemyDelay = 2;

	while (!gameLoop.gameOver)
	{
		BufferFlip();
		float deltaTime = DeltaTime() / 1000.f;
		ScreenClear(BLACK);

		////////////////////////////////////
		// Update stuff
		UpdatePlayer(player, deltaTime);
		for (int i = 0; i < 50; ++i)
			if (bullets[i].lifeTime >= 0)
				UpdateBullet(bullets[i], deltaTime);


		for (int i = 0; i < 50; ++i)
			if (enemies[i].isAlive)
				UpdateEnemy(enemies[i], deltaTime);

		for (int i = 0; i < 50; ++i)
			if (explosions[i].lifetime >= 0)
				UpdateExplosion(explosions[i], deltaTime);

		///////////////////////////////////
		// Check and respond for collision
		
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j)
				if(bullets[j].lifeTime > 0 && enemies[i].isAlive)
					if (EnemyBulletCollision(enemies[i], bullets[j]))
					{
						bullets[j].lifeTime = 0;
						enemies[i].isAlive = false;
						enemies[i].playDeath = true;
					}

		for(int i = 0; i < 50; ++i)
			if (enemies[i].isAlive)
				if (PlayerEnemyCollision(player, enemies[i]))
				{
					enemies[i].isAlive = false;
					// player dies? loses HP?
					if (player.hp > 0)
						player.hp--;
					else
					{
						player.isDead = true;
						// TODO Implement End Game Menu
						gameLoop.playerLose = true;
						gameLoop.gameOver = true;
					}
				}
		////////////////////////////
		// Spawning Stuff - Enemies/bullets
 		if (player.firedShot)
		{
			for (int i = 0; i < 50; ++i)
			{
				if(bullets[i].lifeTime < 0)
				{
					InitBullet(bullets[i], player);						
					break;
				}
			}
			player.firedShot = false;
		}

		enemyTimer -= deltaTime;
		if (enemyTimer < 0)
		{
			for (int i = 0; i < 50; ++i)
			{
				if (enemies[i].isAlive == false)
				{
					InitEnemy(enemies[i]);
					enemyTimer = enemyDelay;
					enemyDelay *= 0.98f;
					break;
				}
			}
		}

		for(int i = 0; i < 50; ++i)
			if(enemies[i].playDeath)
				for (int k = 0; k < 50; ++k)
					if (explosions[k].lifetime < 0)
					{
						InitExplosion(explosions[k], enemies[i].x, enemies[i].y);
						enemies[i].playDeath = false;
						break;
					}

		/////////////////////////////
		// Drawing Stuff - all the things
		for (int i = 0; i < 50; ++i)
			if (bullets[i].lifeTime >= 0)
				DrawBullet(bullets[i]);

		for (int i = 0; i < 50; ++i)
			if (enemies[i].isAlive)
				DrawEnemy(enemies[i]);

		for (int i = 0; i < 50; ++i)
			if (explosions[i].lifetime >= 0)
				DrawExplosion(explosions[i]);
		DrawPlayer(player);		
	}

	// Checks to ensure the proper screen comes up when leaving the game loop
	if (gameLoop.playerWin && gameLoop.gameOver)
	{
		gameLoop.playerLose = false;
		gameLoop.playerQuit = false;
		return;
	}
	else if (gameLoop.playerLose && gameLoop.gameOver)
	{
		gameLoop.playerWin = false;
		gameLoop.playerQuit = false;
		return;
	}
	else if (gameLoop.gameOver && gameLoop.playerQuit)
	{
		gameLoop.playerWin = false;
		gameLoop.playerLose = false;
		return;
	}
	else
	{
		gameLoop.playerLose = false;
		gameLoop.playerQuit = false;
		gameLoop.playerWin = false;
		return;
	}
}