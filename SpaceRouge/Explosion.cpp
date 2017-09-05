#include "Explosion.h"
#include "Screen.h"

// Initializes the explosion
void InitExplosion(Explosion &explosion, float posX, float posY)
{
	// Sets the explosions position and lifetime
	explosion.x = posX;
	explosion.y = posY;
	explosion.lifetime = 1.8f;
}

// Updates the explosion
void UpdateExplosion(Explosion &explosion, float deltaTime)
{
	// Counts down the lifetime using delta time
	explosion.lifetime -= deltaTime;
}

// Draws the explosion animation
void DrawExplosion(Explosion &explosion)
{
	if (explosion.lifetime > 1.2)
	{
		SetChar(explosion.x, explosion.y, 'X', DARK_RED, BLACK);
	}
	else if (explosion.lifetime > .7)
	{
		SetChar(explosion.x, explosion.y, '*', DARK_YELLOW, BLACK);
	}
	else //if e.lifetime > 0
	{
		SetChar(explosion.x, explosion.y, '+', LIGHT_BLUE, BLACK);
	}
}
