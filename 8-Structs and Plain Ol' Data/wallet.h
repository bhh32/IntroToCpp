#pragma once
#ifndef WALLET_H
#define WALLET_H

struct piggybank
{
	int oneDollarBills = 5;
	int twoDollarBills = 5;
	int fiveDollarBills = 5;
	int quarters = 4;
	int dimes = 5;
	int nickles = 20;
	int pennies = 100;

	// Returns the total monetary value of all dollar bills.
	float calcPiggybankNotes(piggybank piggy);

	// Returns the total monetary value of all coins.
	float calcPiggybankCoins(piggybank piggy);

	// Returns the total monetary value of the piggybank's contents.
	float calcPiggybankTotal(piggybank piggy);
};
#endif WALLET_H