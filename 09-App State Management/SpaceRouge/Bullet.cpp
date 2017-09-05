#include "Bullet.h"
#include "Screen.h"
#include "Player.h"

void UpdateBullet(Bullet bullet, float deltaTime)
{
	if (bullet.lifeTime > 0)
		bullet.y += deltaTime * bullet.speed;

	bullet.lifeTime--;
}

void DrawBullet(Bullet bullet[], Bullet &currentBullet, Player &player)
{
	currentBullet.x = player.x;
	currentBullet.y = player.y;

	if (currentBullet.intShot)
	{
		SetChar(player.x, player.y, '|', WHITE, BLACK);
		currentBullet.intShot = false;
		currentBullet.beenshot = true;
	}
	else
	{
		for (int shots = 0; shots < 50; shots++)
		{
			if (bullet[shots].beenshot && bullet[shots].lifeTime != 0)
			{
				SetChar(bullet[shots].x, bullet[shots].y++, '|', WHITE, BLACK);
			}
			else if (!bullet[shots].beenshot || bullet[shots].lifeTime <= 0)
			{
				SetChar(bullet[shots].x, bullet[shots].y++, ' ', WHITE, BLACK);
				bullet[shots].lifeTime = player.shotInitLife;
			}
		}
	}
}