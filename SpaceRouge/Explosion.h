#pragma once
#ifndef EXPLOSION_H
#define EXPLOSION_H

struct Explosion
{
	float x, y;
	float lifetime;
};

// Initializes the Explosion
void InitExplosion(Explosion &e, float x, float y);

// Updates the explosion animation
void UpdateExplosion(Explosion &e, float dt);

// Draws the explosion
void DrawExplosion(Explosion &e);

#endif EXPLOSION_H