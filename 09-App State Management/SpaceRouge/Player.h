#pragma once

#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	float x, y, speedX, speedY;

	float trail;
	bool thrusting;
	bool firedShot;
	float shotInitLife;
};

void DrawPlayer(Player player);
void UpdatePlayer(Player &player, float deltaTime);

#endif PLAYER_H
