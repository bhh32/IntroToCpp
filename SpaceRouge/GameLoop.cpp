#include <iostream>
#include<Windows.h>
#include "GameLoop.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Collision.h"
#include "Explosion.h"

bool GameLoop(MainGameLoop &gameLoop)
{
	ScreenInit();

	

	Player player;
	InitPlayer(player);

	gameLoop.gameOver = false;
	gameLoop.playerWin = false;
	gameLoop.playerLose = false;
	

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

	while(!gameLoop.gameOver)
	{
		BufferFlip();
		float deltaTime = DeltaTime() / 1000.f;
		ScreenClear(BLACK);

		////////////////////////////////////
		// Update stuff
		gameLoop.playerScore = player.score;

		UpdatePlayer(player, deltaTime, gameLoop);

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
				if (bullets[j].lifeTime > 0 && enemies[i].isAlive)
					if (EnemyBulletCollision(enemies[i], bullets[j]))
					{
						bullets[j].lifeTime = 0;
						enemies[i].isAlive = false;
  						enemies[i].playDeath = true;
						player.score++;
						gameLoop.playerScore = player.score;
					}

		for (int i = 0; i < 50; ++i)
		{
			if (enemies[i].isAlive)
				if (PlayerEnemyCollision(player, enemies[i]))
				{
					enemies[i].isAlive = false;
					
					

					if (player.hp > 0)
						player.hp--;
					
					if(player.hp <= 0)
					{
						player.isDead = true;
						gameLoop.playerScore = ReturnScore(player.score);
						ScreenClear(BLACK);
						break;
					}
				}
		}

		if (gameLoop.playerScore >= 50)
			gameLoop.playerWin = true;
		////////////////////////////
		// Spawning Stuff - Enemies/bullets

		// Spawn Bullets
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

		// Spawn Enemies
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

		// Spawn Explosions between Bullets and Enemies
		for (int i = 0; i < 50; ++i)
		{
			if (enemies[i].playDeath)
				for (int k = 0; k < 50; ++k)
					if (explosions[k].lifetime < 0)
					{
						InitExplosion(explosions[k], enemies[i].x, enemies[i].y);
						enemies[i].playDeath = false;
						break;
					}
		}
		// Spawn an explosion if the player is killed
		
			if (player.isDead)
				for (int l = 0; l < 50; ++l)
					if (explosions[l].lifetime < 0)
					{
						InitExplosion(explosions[l], player.x, player.y);
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

		if (!player.isDead)
		{
			DrawPlayer(player);
			DrawHP(player);
			DrawScore(player, gameLoop);
		}
		if (gameLoop.playerWin)
		{
			gameLoop.gameOver = true;
			break;
		}
		else if (gameLoop.playerLose)
		{
			gameLoop.gameOver = true;
			break;
		}
		else if (gameLoop.playerQuit)
		{
			gameLoop.gameOver = true;
			break;
		}

	}
	BufferFlip();
	return gameLoop.gameOver;
}