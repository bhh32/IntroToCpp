#pragma once

#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	// Player Attributes Variables
	float x, y, speedX, speedY;
	int hp;
	bool isDead;

	// Thrusting Variables
	float trail;
	bool thrusting;	

	// Fire Cannon Variables
	float shotInitLife;
	int altFire;
	bool firedShot;
	float fireDelay;
	float fireTimer;
};

// Draws the player
void DrawPlayer(Player player);

// Updates the player
void UpdatePlayer(Player &player, float deltaTime);

#endif PLAYER_H
