#include "wallet.h"

float calcPiggybankNotes(piggybank piggy)
{
	float dollarBillsTotal = (float)piggy.oneDollarBills * 1.0f;
	float twoDollarBillsTotal = (float)piggy.twoDollarBills * 2.0f;
	float fiveDollarBillsTotal = (float)piggy.fiveDollarBills * 5.0f;

	float totalMonetaryValueOfBills = dollarBillsTotal + twoDollarBillsTotal + fiveDollarBillsTotal;

	return totalMonetaryValueOfBills;
}

float calcPiggybankCoins(piggybank piggy)
{
	float quartersTotal = piggy.quarters * .25f;
	float dimesTotal = piggy.dimes * .10f;
	float nicklesTotal = piggy.nickles * .05f;
	float penniesTotal = piggy.pennies * .01f;

	float coinsTotal = quartersTotal + dimesTotal + nicklesTotal + penniesTotal;

	return coinsTotal;
}

float calcPiggybankTotal(piggybank piggy)
{
	float billsTotal = calcPiggybankNotes(piggy);
	float coinsTotal = calcPiggybankCoins(piggy);

	return billsTotal + coinsTotal;
}