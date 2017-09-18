#pragma once
#ifndef MAIN_H
#define MAIN_H
#include "GameLoop.h"

bool choiceMade;

void Credits();
void WinScreen(MainGameLoop &gameLoop);
void LoseScreen(MainGameLoop &gameLoop);
void QuitScreen(MainGameLoop &gameLoop);

#endif MAIN_H