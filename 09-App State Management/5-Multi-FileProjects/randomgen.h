#ifndef RANDOMGEN_H
#define RANDOMGEN_H
#pragma once

class RandomGenerator
{
public:
	void SeedRng(int x);
	int Rng();
	int RngRange(int x, int y);
	bool Rngb();
	bool RngbChance(int x);
};

#endif RANDOMGEN_H