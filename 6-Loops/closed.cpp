#include <iostream>
#include "closed.h"

using std::cout;
using std::cin;

void Closed::ForLoopAscending()
{
	for (int i = 1; i < 101; i++)
	{
		cout << i << "\n";
	}
}

void Closed::WhileLoopDescending()
{
	while (whileLoopCondition > 0)
	{
		cout << whileLoopCondition << "\n";

		whileLoopCondition--;
	}
}

void Closed::DoWhileLoopYears()
{
	do
	{
		cout << doWhileLoopCondition << "\n";

		doWhileLoopCondition++;

	} while (doWhileLoopCondition < 2018);
}

void Closed::ThreeFavPosNumbers()
{

}