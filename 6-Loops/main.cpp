#include <iostream>
#include "walkthrough.h"
#include "closed.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Walkthrough wt;

	cout << "Walkthrough Activity\n";
	cout << "While Loop\n";
	wt.WhileLoop();	
	cout << "\n";
	cout << "For Loop\n";
	wt.ForLoop();
	cout << "\n";
	cout << "Do, While Loop\n";
	wt.DoWhileLoop();
	cout << "\n";
	cout << "User Validation Do While Loop\n";
	wt.UserValidation();
	cout << "\n";

	cout << "Closed Activities\n";
	Closed closed;
	cout << "For Loop Ascending\n";
	closed.ForLoopAscending();

	system("pause");

	return 0;
}