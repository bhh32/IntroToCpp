#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// Prints 'Hello AIE' to the console
	cout << "Hello AIE\n";

	// Skips a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Skips a line
	cout << "\n";

	// Prints a list of tracks on their own line
	cout << "Five Finger Death Punch - House of the Rising Sun\n";
	cout << "Five Finger Death Punch - Nemesis\n";
	cout << "Linkin Park - Crawling\n";
	cout << "Jim Croche - Time in a Bottle\n";
	cout << "Taylor Swift - Bad Blood\n";
	cout << "Taylor Swift - Shake It Off\n";
	cout << "Casper Baby Pants - Butterfly Driving a Truck\n";


	// Skips a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Skips a line
	cout << "\n";
	
	// For loop that prints 5 - 0
	for (int i = 5; i > -1; --i)
	{
		// Prints current value of i to screen
		cout << i << endl;
	}

	// Skips a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Skip a line
	cout << "\n";

	/* Counting */
	// For loop ascends up to 5
	for (int i = 0; i < 6; i++)
	{
		cout << i << endl;
		// Checks to see if i is the same as 5
		if (i == 5)
		{
			// if it is... this for loop begins to decend from 4 for the countdown
			for (int j = 4; j > -1; j--)
			{
				cout << j << endl;
			}
		}
	}	

	// skips a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Skips a line
	cout << "\n";

	// SyntacticalErrors-A)
	cout << "SyntacticalErrors-A)\n";
	cout << "Howdy AIE\n";
	cout << "It's a fine day today as any!\n";
	cout << "I really wish I had some potatoes...\n";

	// Skip a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Skip a line
	cout << "\n";

	// SyntacticalErrors-B)
	cout << "SyntacticalErrors-B)\n";
	cout << "Four score and seven years ago\n";
	cout << "our fathers brought forth on this continent,\n";
	cout << "a new nation,\n";
	cout << "conceived in Liberty, and dedicated to the proposition\n";
	cout << "that all men are created equal.\n";

	cout << "Now we are engaged in a great civil war,\n";
	cout << "testing whether that nation, or any nation\n";
	cout << "so conceived and so dedicated, can long endure.\n";

	// Skip a line
	cout << "\n";

	// Pauses the system and waits for user input
	system("pause");

	// Ends the program
	return 0;
}