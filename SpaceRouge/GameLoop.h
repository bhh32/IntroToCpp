#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H


struct MainGameLoop
{
	int playerScore;

	bool gameOver;
	bool playerWin;
	bool playerLose;
	bool playerQuit;
};

bool GameLoop(MainGameLoop &gameLoop);

#endif GAMELOOP_H