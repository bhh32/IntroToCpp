#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "GameLoop.h"

struct Player
{
	// Player Attributes Variables
	float x, y, speedX, speedY;
	int hp;
	int score;
	bool isDead;
	bool pickupCollide;

	// Thrusting Variables
	float trail;
	bool thrusting;	

	// Fire Cannon Variables
	float shotInitLife;
	int altFire;
	int fireRate;
	bool firedShot;
	float fireDelay;
	float fireTimer;
};

// Initializes the player values
void InitPlayer(Player &player);

// Draws the player
void DrawPlayer(Player &player);

// Display The Players score
void DrawScore(Player &player, MainGameLoop &gameLoop);

void DrawHP(Player &player);

// Updates the player
void UpdatePlayer(Player &player, float deltaTime, MainGameLoop &gameLoop);

// Returns the player's score.
int ReturnScore(int &score);

#endif PLAYER_H
