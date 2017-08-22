#include "walkthrough.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Walkthrough::WhileLoop()
{
	while (whileLoopCondition < 10)
	{
		cout << whileLoopCondition << "\n";

		whileLoopCondition++;
	}
}

void Walkthrough::ForLoop()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\n";
	}
}

void Walkthrough::DoWhileLoop()
{
	do
	{
		cout << doWhileCondition << "\n";

		doWhileCondition++;
	} while (doWhileCondition < 10);
}

void Walkthrough::UserValidation()
{
	doWhileCondition = 0;
	printf("Enter a whole number between 1 - 10: ");
	cin >> userInput;

	do
	{
		if (doWhileCondition == userInput)
		{
			cout << "Yay! You followed directions! Your number is: " << doWhileCondition << "\n";
			break;
		}

		doWhileCondition++;

	} while (doWhileCondition < 11);

	if (userInput > 10)
	{
		cout << "You didn't follow directions... your number was: " << userInput << "\n";
	}
}