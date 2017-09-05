#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H

struct MainGameLoop
{
	bool gameOver;
	bool playerWin;
	bool playerLose;
	bool playerQuit;
};

void GameLoop(MainGameLoop &gameLoop);

#endif GAMELOOP_H