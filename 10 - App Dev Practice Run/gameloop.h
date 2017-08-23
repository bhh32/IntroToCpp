#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H
struct Entities;
class GameLoop
{
public:
	// variables
	bool gameIsOver = false;
	bool battleOver = false;

	// functions
	void MainGameLoop();
	void Battle(Entities &player, Entities &enemy);
	
};
#endif  GAMELOOP_H