#pragma once
#ifndef PICKUP_H
#define PICKUP_H

#include "Bullet.h"

struct Pickup
{
	float x;
	float y;
	float speedX, speedY;

	int velX;
	float startX;
	float opRange;
	bool isPickedUp;

};

// Draws the pickup
void DrawPickup(Pickup &pickup);

// Updates the pickup movement
void UpdatePickup(Pickup &pickup, float deltaTime);

// Initializes the pickup
void InitPickup(Pickup &pickup);

#endif PICKUP_H