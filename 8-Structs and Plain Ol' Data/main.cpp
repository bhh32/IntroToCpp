#include <iostream>
#include "wallet.h"
#include "student.h"

using std::cout;

int main()
{
	cout << "Closed Activities\n";
	piggybank piggy;

	float bills = piggy.calcPiggybankNotes(piggy);
	float coins = piggy.calcPiggybankCoins(piggy);
	float total = piggy.calcPiggybankTotal(piggy);

	cout << "$" << bills << "\n";
	cout << "$" << coins << "\n";
	cout << "$" << total << "\n";

	cout << "\n";

	cout << "Open Activities\n";



	system("pause");

	return 0;
}