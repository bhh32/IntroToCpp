#include "playervszombie.h"
#include <iostream>

void PlayerAttack(playervszombie &pvz)
{
	pvz.zombieHP -= (pvz.playerAP - pvz.zombieDP);

	

	std::cout << "The Zombie was hit!\n" << "Zombie Health is now: " << pvz.zombieHP << "\n";
}

void ZombieAttack(playervszombie &pvz)
{
	pvz.playerHP -= (pvz.zombieAP - pvz.playerDP);

	std::cout << "The Player was hit!\n" << "Player Health is now: " << pvz.playerHP << "\n";	
}

void PlayerDies(playervszombie &pvz)
{
	std::cout << "The Zombie wins! The player died!\n";
	pvz.battleOver = true;
}

void ZombieDies(playervszombie &pvz)
{
	std::cout << "You win! The Zombie is DEAD!\n";
	pvz.battleOver = true;
}

void Battle()
{
	playervszombie pvz;
	while (!pvz.battleOver)
	{
		PlayerAttack(pvz);
		if (pvz.zombieHP <= 0)
		{
			ZombieDies(pvz);
			break;
		}
		system("pause");
		std::cout << "\n";
		ZombieAttack(pvz);
		if (pvz.zombieHP <= 0)
			PlayerDies(pvz);
		system("pause");
		std::cout << "\n";
	}
}