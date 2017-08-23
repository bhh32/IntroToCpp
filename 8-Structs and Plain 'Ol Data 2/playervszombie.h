#pragma once
#ifndef PLAYERVSZOMBIE_H
#define PLAYERVSZOMBIE_H

struct playervszombie
{
public:

	// variables
	int playerHP = 20;
	int zombieHP = 15;
	int playerAP = 7;
	int zombieAP = 10;
	int playerDP = 5;
	int zombieDP = 3;
	bool battleOver = false;
};

// functions
void PlayerAttack(playervszombie &pvz);
void ZombieAttack(playervszombie &pvz);
void PlayerDies(playervszombie &pvz);
void ZombieDies(playervszombie &pvz);
void Battle();

#endif PLAYERVSZOMBIE_H
