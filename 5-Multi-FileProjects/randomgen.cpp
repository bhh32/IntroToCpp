#include <iostream>
#include <ctime>
#include "randomgen.h"

void RandomGenerator::SeedRng(int x)
{
	srand(time_t(x));
}

int RandomGenerator::Rng()
{
	int randNum = rand() % 100 + 1;
	return randNum;
}

//int RandomGenerator::RngRange(int x, int y)
//{
//	rand() % x + (x - y);
//}

bool RandomGenerator::Rngb()
{
	/*srand(time(nullptr));*/
	int randNum1 = Rng();
	/*srand(time(nullptr));*/
	int randNum2 = Rng();

	if (randNum1 < randNum2)
		return false;
	else
		return true;

}

bool RandomGenerator::RngbChance(int x)
{
	srand(time_t(x));
	int randNum = RngRange(1, 2);

	/*if(randNum > )*/

	return true;
}
