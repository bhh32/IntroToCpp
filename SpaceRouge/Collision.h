#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

// Returns whether or not the Player and Enemy Collided
bool PlayerEnemyCollision(Player &p, Enemy &e);

// Returns whether or not the Enemy and Bullet Collided
bool EnemyBulletCollision(Enemy &e, Bullet &b);

#endif COLLISION_H