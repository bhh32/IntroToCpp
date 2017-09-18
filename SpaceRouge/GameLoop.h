#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>

struct MainGameLoop
{
	int playerScore;
	
	int highScore1 = 0;
	int highScore2 = 0;
	int highScore3 = 0;

	std::string name;
	std::string hsName1;
	std::string hsName2;
	std::string hsName3;

	bool gameOver;
	bool playerWin;
	bool playerLose;
	bool playerQuit;
};

bool GameLoop(MainGameLoop &gameLoop);
void SaveHighScore(MainGameLoop &gameLoop, std::string name);
void LoadHighScore(MainGameLoop &gameLoop);
void PrintHighScore();

#endif GAMELOOP_H