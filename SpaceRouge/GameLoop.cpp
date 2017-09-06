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
	// Initiate the double buffers
	ScreenInit();

	// Create a player
	Player player;
	// Initiate that player
	InitPlayer(player);

	// Set the game state conditions to false
	gameLoop.gameOver = false;
	gameLoop.playerWin = false;
	gameLoop.playerLose = false;
	
	// Create the enemies
	Enemy *enemies = new Enemy[50];
	for (int i = 0; i < 50; ++i)
	{
		enemies[i].isAlive = false;
	}

	// Create the bullets
	Bullet *bullets = new Bullet[50];
	for (int i = 0; i < 50; i++)
	{
		bullets[i].lifeTime = -1;
	}

	// Create the explosions
	Explosion *explosions = new Explosion[50];
	for (int i = 0; i < 50; i++)	
		explosions[i].lifetime = -1;
	
	// Create the spawn timers
	float enemyTimer = 2;
	float enemyDelay = 2;

	// Main Game Loop
	while(!gameLoop.gameOver)
	{
		// Flip the write and display buffers
		BufferFlip();
		// create delta time
		float deltaTime = DeltaTime() / 1000.f;
		// Clear the write buffer
		ScreenClear(BLACK);

		////////////////////////////////////
		// Update stuff

		// Set the gameLoops playerScore variable to the players score
		gameLoop.playerScore = player.score;

		// Update the player
		UpdatePlayer(player, deltaTime, gameLoop);

		// Loop through all of the bullets
		for (int i = 0; i < 50; ++i)
			// Get the bullets that are alive
			if (bullets[i].lifeTime >= 0)
				// Update all of the bullets that are alive
				UpdateBullet(bullets[i], deltaTime);

		// Loop through all of the enemies
		for (int i = 0; i < 50; ++i)
			// Get the enemies that are alive
			if (enemies[i].isAlive)
				// Update all alive enemies
				UpdateEnemy(enemies[i], deltaTime);

		// Loop through all of the explosions
		for (int i = 0; i < 50; ++i)
			// Get the explosions that are alive
			if (explosions[i].lifetime >= 0)
				// Update all of the alive explosions
				UpdateExplosion(explosions[i], deltaTime);

		///////////////////////////////////
		// Check and respond for collision
		
		// Checks for collions between the enemies and bullets
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

		// Checks for collision between the player and the enemies
		for (int i = 0; i < 50; ++i)
		{
			// Checks to ensure that the collided enemies are alive
			if (enemies[i].isAlive)
				if (PlayerEnemyCollision(player, enemies[i]))
				{
					// If they are it sets them to dead (isAlive = false)
					enemies[i].isAlive = false;					

					// Checks to make sure the player's hp is greater than 0
					if (player.hp > 0)
						// ... if it is decrement the hp by 1
						player.hp--;
					
					// Checks to see if the player's hp is <= 0
					if(player.hp <= 0)
					{
						// ... if it is, set player to dead
						player.isDead = true;
						
						// ... ensure the game loop score is set to the player's score
						gameLoop.playerScore = ReturnScore(player.score);

						// Clear the Screen
						ScreenClear(BLACK);

						// Break from this for loop
						break;
					}
				}
		}

		// Checks to see if the players score is >= 50
		if (gameLoop.playerScore >= 50)
		{
			// ... if it is set the win condition to true
			gameLoop.playerWin = true;

			// break from the game loop
			break;
		}

		////////////////////////////
		// Spawning Stuff - Enemies/bullets

		// Spawn Bullets
 		if (player.firedShot)
		{
			// Cycle through the bullets to find a bullet that can be shot
			for (int i = 0; i < 50; ++i)
			{
				// if the lifeTime < 0 it's ok to be shot
				if(bullets[i].lifeTime < 0)
				{
					// Initiate the bullet
					InitBullet(bullets[i], player);
					// break from this for loop
					break;
				}
			}

			// Ensure firedShot flag is set back to false
			player.firedShot = false;
		}

		// Spawn Enemies
		// Decrement the enemy spawn timer to the next spawn
		enemyTimer -= deltaTime;

		// Check to see if enemyTimer is less than 0
		if (enemyTimer < 0)
		{
			// ... if it is, loop through to find pooled enemy that can be spawned
			for (int i = 0; i < 50; ++i)
			{
				// if the enemy is not alive...
				if (enemies[i].isAlive == false)
				{
					// Initialize the enemy
					InitEnemy(enemies[i]);
					// Set the enemy spawn timer to the spawn delay time
					enemyTimer = enemyDelay;
					// Creates a harder game by making the enemy delay approach, but never reach, zero
					enemyDelay *= 0.98f;
					// break from this for loop
					break;
				}
			}
		}

		// Spawn Explosions between Bullets and Enemies
		for (int i = 0; i < 50; ++i)
		{
			// if the enemy's playDeath flag is true
			if (enemies[i].playDeath)
			{
				// ... loop through to see what explosion in the pool can be used
				for (int k = 0; k < 50; ++k)
				{
					// ... if the lifeTime is < 0 it is an unused explosion and can be used
					if (explosions[k].lifetime < 0)
					{
						// ... Initialize the explosion at the enemy's current x and y positions
						InitExplosion(explosions[k], enemies[i].x, enemies[i].y);
						// ... set the playDeath flag back to false
						enemies[i].playDeath = false;
						// break from this loop
						break;
					}
				}
			}
		}

		/////////////////////////////
		// Drawing Stuff - all the things
		
		// Cycle through to get an available bullet from the pool
		for (int i = 0; i < 50; ++i)
			// if the bullet is available, draw it
			if (bullets[i].lifeTime >= 0)
				DrawBullet(bullets[i]);

		// Cycle through the enemies to find one that is available from the pool
		for (int i = 0; i < 50; ++i)
			// if the enemy is available, draw it
			if (enemies[i].isAlive)
				DrawEnemy(enemies[i]);

		// Cycle though the explosions to find one that is available from the pool
		for (int i = 0; i < 50; ++i)
			// if the explosion is available, draw it
			if (explosions[i].lifetime >= 0)
				DrawExplosion(explosions[i]);

		// If the player isn't dead
		if (!player.isDead)
		{
			// Draw the player, player hp, and score
			DrawPlayer(player);
			DrawHP(player);
			DrawScore(player, gameLoop);
		}

		// If the win condition is true
		if (gameLoop.playerWin)
		{
			// ... say the game is over
			gameLoop.gameOver = true;
			// break from the game loop
			break;
		}
		// If the loss condition is true
		else if (gameLoop.playerLose)
		{
			// ... say the game is over
			gameLoop.gameOver = true;
			// break from the game loop
			break;
		}
		// If the player hit esc to trigger the quit condition
		else if (gameLoop.playerQuit)
		{
			// ... say the game is over
			gameLoop.gameOver = true;
			// break from the game loop
			break;
		}

	}
	// return that the game is over
	return gameLoop.gameOver;
}