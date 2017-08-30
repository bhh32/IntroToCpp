#include "Bullet.h"

void BulletUpdate(bool &hasShot, int &shotY)
{
	if (shotY > 4)
		shotY--;
	else
		hasShot = false;
}