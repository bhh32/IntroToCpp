#pragma once
#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	char pos[50][100];
	int lives;
};

void SetPlayerInitialPosition();

#endif PLAYER_H