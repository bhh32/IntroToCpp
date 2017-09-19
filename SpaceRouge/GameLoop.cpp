#include <iostream>
#include <fstream>
#include <sstream>
#include<Windows.h>
#include "GameLoop.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Collision.h"
#include "Explosion.h"
#include "Pickup.h"

using std::fstream;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

bool GameLoop(MainGameLoop &gameLoop)
{

	cout << "                                                   Before we start the game, What is your name?\n";

	while (true)
	{
		cin >> gameLoop.name;

		if (gameLoop.name == " ")
			cout << "                                          You didn't enter your name, please do so: ";
		else
			break;
	}

	// Initiate the double buffers
	ScreenInit();

	// Create a player
	Player player;
	// Initiate that player
	InitPlayer(player);

	// Set the game state conditions to false
	gameLoop.gameOver = false;
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
	Explosion *explosions = new Explosion[200];
	for (int i = 0; i < 200; i++)
		explosions[i].lifetime = -1;

	// Create the pickups
	Pickup *pickups = new Pickup[50];
	for (int i = 0; i < 50; ++i)
		pickups[i].isPickedUp = true;

	// Create the spawn timers
	float enemyTimer = 2;
	float enemyDelay = 2;
	float pickupTimer = 10.f;
	float pickupDelay = 20.f;

	float deltaTime = DeltaTime();

	// Main Game Loop
	while (!gameLoop.gameOver)
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
				UpdateBullet(bullets[i], player, deltaTime);

		// Loop through all of the enemies
		for (int i = 0; i < 50; ++i)
			// Get the enemies that are alive
			if (enemies[i].isAlive)
				// Update all alive enemies
				UpdateEnemy(enemies[i], deltaTime);

		// Loop through all of the explosions
		for (int i = 0; i < 200; ++i)
		{
			// Get the explosions that are alive
			if (explosions[i].lifetime >= 0)
			{	// Update all of the alive explosions
				UpdateExplosion(explosions[i], deltaTime);
			}
		}

		// Loop through all of the pickups
		for (int i = 0; i < 50; ++i)
		{
			// Get the pickups that haven't been picked up
			if (!pickups[i].isPickedUp)
			{
				// Update all of the unpicked up pickups
				UpdatePickup(pickups[i], deltaTime);
			}
		}
		///////////////////////////////////
		// Check and respond for collision

		// Checks for collions between the enemies and bullets
		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				if (bullets[j].lifeTime > 0 && enemies[i].isAlive)
				{
					if (EnemyBulletCollision(enemies[i], bullets[j]))
					{
						bullets[j].lifeTime = 0;
						enemies[i].isAlive = false;
						enemies[i].playDeath = true;
						player.score++;
						gameLoop.playerScore = player.score;
					}
				}
			}
		}

		// Checks for collision between the player and the enemies
		for (int i = 0; i < 50; ++i)
		{
			// Checks to ensure that the collided enemies are alive
			if (enemies[i].isAlive)
			{
				if (PlayerEnemyCollision(player, enemies[i]))
				{
					// If they are it sets them to dead (isAlive = false)
					enemies[i].isAlive = false;

					// Checks to make sure the player's hp is greater than 0
					if (player.hp > 0)
					{	// ... if it is decrement the hp by 1
						player.hp--;
					}
					// Checks to see if the player's hp is <= 0
					if (player.hp <= 0)
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
		}

		// Checks for collision between the player and the pickups
		for (int i = 0; i < 50; ++i)
		{
			// Checks to ensure that the collided haven't been picked up
			if (!pickups[i].isPickedUp)
			{
				if (PlayerPickupCollision(player, pickups[i]))
				{
					// If they haven't it sets them to picked up
					pickups[i].isPickedUp = true;
					
					// If the pickup is collided with, set the flag for the player and bullets
					player.pickupCollide = true;
					
					// Clear the Screen
					ScreenClear(BLACK);

					// Break from this for loop
					break;
				}
			}
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
				if (bullets[i].lifeTime < 0)
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

		// Spawn Pickups
		pickupTimer -= deltaTime;

		// Check to see if pickupTimer is less than 0
		if (pickupTimer < 0)
		{
			// ... if it is, loop through to find pooled pickup that can be spawned
			for (int i = 0; i < 50; ++i)
			{
				// if the pickup is picked up
				if (pickups[i].isPickedUp)
				{
					// Initialize the pickup
					InitPickup(pickups[i]);

					// Set the pickup spawn timer to the spawn delay time
					pickupTimer = pickupDelay;

					// break from the loop
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
				for (int k = 0; k < 200; ++k)
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


			/////////////////////////////
			// Drawing Stuff - all the things

			// Cycle through to get an available bullet from the pool
			for (int i = 0; i < 50; ++i)
				// if the bullet is available, draw it
				if (bullets[i].lifeTime >= 0)
				{
					DrawBullet(bullets[i]);
				}
			// Cycle through the enemies to find one that is available from the pool
			for (int i = 0; i < 50; ++i)
				// if the enemy is available, draw it
				if (enemies[i].isAlive)
					DrawEnemy(enemies[i]);

			// Cycle through the pickups to find one that is available from the pool
			for (int i = 0; i < 50; ++i)
			{
				if (!pickups[i].isPickedUp)
					DrawPickup(pickups[i]);
			}

			// Cycle though the explosions to find one that is available from the pool
			for (int i = 0; i < 200; ++i)
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

			// If the loss condition is true
			if (gameLoop.playerLose)
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
	
	}
	SetString(55, 35, "GAME OVER! PRESS ANY KEY TO CONTINUE!", LIGHT_RED, BLACK);
	BufferFlip();
	system("pause");

// return that the game is over
return gameLoop.gameOver; 
}

// Saves the high scores if applicable
	void SaveHighScore(MainGameLoop &gameLoop, string name)
	{
		fstream highScoreFile;
		bool endOfFile = false;
		string buffer;

		LoadHighScore(gameLoop);

		highScoreFile.open("HighScores.txt", std::ios::out);

		if (highScoreFile.is_open())
		{
			while (true)
			{
				if (gameLoop.playerScore > gameLoop.highScore1)
				{
					gameLoop.highScore2 = gameLoop.highScore1;
					gameLoop.hsName2 = gameLoop.hsName1;

					gameLoop.highScore1 = gameLoop.playerScore;
					gameLoop.hsName1 = name;
				}
				else if (gameLoop.playerScore < gameLoop.highScore1 && gameLoop.playerScore > gameLoop.highScore2)
				{
					gameLoop.highScore3 = gameLoop.highScore2;
					gameLoop.hsName3 = gameLoop.hsName2;

					gameLoop.highScore2 = gameLoop.playerScore;
					gameLoop.hsName2 = name;

				}
				else if (gameLoop.playerScore < gameLoop.highScore2 && gameLoop.playerScore > gameLoop.highScore3)
				{
					gameLoop.highScore3 = gameLoop.playerScore;
					gameLoop.hsName3 = name;
				}

				break;
			}

			highScoreFile << gameLoop.hsName1 << " " << gameLoop.highScore1 << endl;
			highScoreFile << gameLoop.hsName2 << " " << gameLoop.highScore2 << endl;
			highScoreFile << gameLoop.hsName3 << " " << gameLoop.highScore3 << endl;
		}

		highScoreFile.flush();
		highScoreFile.close();
	}

	// Loads the high scores in from a .txt file
	void LoadHighScore(MainGameLoop &gameLoop)
	{
		string buffer;
		string name;
		string hs;
		string charSplit;
		string charActual;
		fstream highScoreFile;

		int count = 0;

		// Opens the file for reading
		highScoreFile.open("HighScores.txt", std::ios::in);

		// Checks to see if the file is open
		if (highScoreFile.is_open())
		{
			while (getline(highScoreFile, buffer))
			{
				// Splits the string into two sections
				std::istringstream iss(buffer);
				// This section is put into the name variable
				iss >> name;
				// This section is put into the high score variable
				iss >> hs;

				// Puts the section of data into the appropriate struct variable
				switch (count)
				{
				case 0:
					gameLoop.hsName1 = name;
					gameLoop.highScore1 = std::stof(hs);
					break;
				case 1:
					gameLoop.hsName2 = name;
					gameLoop.highScore2 = std::stof(hs);
					break;
				case 2:
					gameLoop.hsName3 = name;
					gameLoop.highScore3 = std::stof(hs);
					break;
				default:
					cout << "Something went wrong!" << endl;
				}

				// Counts up
				count++;

				// Clears the name and hs strings, prepping them for the next set of data
				name.clear();
				hs.clear();
			}
		}

		// Closes the file
		highScoreFile.close();
	}

// Prints the high scores from the .txt file
void PrintHighScore()
{
	string buffer;
	fstream highScoreFile;

	highScoreFile.open("HighScores.txt");

	if (highScoreFile.is_open())
	{
		while (getline(highScoreFile, buffer))
		{
			cout << buffer << endl;
		}
	}

	highScoreFile.close();
}