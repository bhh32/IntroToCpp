#include <iostream>
#include <ctime>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int Sum(int x, int y); // 1.) Declaring and Defining Functions

/** CLOSED ACTIVITIES **/

// 1.) Function Prototypes
void HelloFunctions();
int Square(int x);
float Decimal(int x, int y);
float Difference(float x, float y, float z);

// 2.) Function Definitions
void Coordinates(int x, int y);

// 3.) Sum of 3 Integers
int Sum(int x, int y, int z);

/** OPEN ACTIVITIES **/

// 1.) Min
int Min(int x, int y);

// 2.) Max
int Max(int x, int y);

// 3.) Clamp
int Clamp(int x, int y, int z);

// 4.) Distance
float Distance(int xA, int yA, int xB, int yB);

// 5.) Estimated Time Of Arrival
int ETA(int xA, int yA, int xB, int yB, int speed);

/** CHALLENGE ACTIVITIES **/

// 1.) LINEAR INTERPOLATION
float Lerp(int x, int y, float z);

// 2.) CLAMP - PART TWO
int Clamp2(int x, int y, int z);

// 3.) HIGH AND LOW GAME
void HighLowGame();

// 4.) TO UPPER OR TO LOWER
char ToUpper(char x);
char ToLower(char x);

// 5.) UNIT TESTING FRAMEWORK
void FunctionTesting();

// MAIN FUNCTION
int main()
{
	Sum(12, 32); // 1.) Declaring and Defining Functions

	Sum(43, 56); // 2.) Calling Upon Functions (in Functions)

	Sum(89, 140); // 2.) Calling Upon Functions (in Functions)

	cout << "\n";

	/** CLOSED ACTIVITIES **/

	// 1.) Function Prototypes
	cout << "Function Prototypes\n";
	HelloFunctions();

	// Test the Square function
	int sqr = Square(4);
	cout << "Your number Squared: " << sqr << endl;

	// Test the Decimal function
	float dec = Decimal(5,3);
	cout << "Your fraction as a decimal: " << dec << endl;

	// Test the Difference function
	float dif = Difference(12.2, 34.1, 76.4);
	cout << "The largest difference is: " << dif << endl;

	cout << "\n";

	// 2.) Function Definitions
	cout << "Function Definitions\n";
	Coordinates(4, 1);
	Coordinates(2, 2);
	Coordinates(0, 3);

	cout << "\n";

	// 3.) Sum of 3 Integers
	cout << "Sum of 3 Integers\n";
	cout << Sum(1, 8, 3) << endl;
	cout << Sum(5, 8, 1) << endl;
	cout << Sum(-5, 6, 2) << endl;
	cout << Sum(0, 12, 7) << endl;
	cout << Sum(7, 3, 4) << endl;

	cout << "\n";

	/** OPEN ACTIVITIES **/

	// 1.) Min
	cout << "Min\n";
	cout << Min(4, 6) << endl;
	cout << Min(5, 2) << endl;
	cout << Min(7, 7) << endl;

	cout << "\n";

	// 2.) Max
	cout << "Max\n";
	cout << Max(4, 6) << endl;
	cout << Max(5, 2) << endl;
	cout << Max(7, 7) << endl;

	cout << "\n";

	// 3.) Clamp
	cout << "Clamp\n";
	cout << Clamp(15, 30, 11) << endl;
	cout << Clamp(2, 7, 5) << endl;
	cout << Clamp(0, 10, -3) << endl;
	cout << Clamp(0, 100, 45) << endl;
	cout << Clamp(25, 30, 30) << endl;
	cout << Clamp(10, 25, 75) << endl;

	cout << "\n";

	// 4.) Distance
	cout << "Distance\n";
	cout << Distance(0, 0, 0, 1) << endl;
	cout << Distance(3, 3, 4, 5) << endl;
	cout << Distance(7, 23, 9, 0) << endl;

	cout << "\n";

	// 5.) Estimated Time Of Arrival
	cout << "Estimated Time of Arrival\n";
	cout << ETA(0, 0, 0, 4, 1) << endl;
	cout << ETA(0, 0, 0, 4, 2) << endl;
	cout << ETA(4, 4, 4, 8, 4) << endl;

	cout << "\n";

	/* CHALLENGE ACTIVITIES */

	// 1.) LINEAR INTERPOLATION
	printf("%g\n", Lerp(2, 4, .5f));
	printf("%g\n", Lerp(1, 100, .25f));
	printf("%g\n", Lerp(1, 2, .04f));
	
	cout << "\n";

	// 2.) CLAMP - PART TWO
	cout << "Clamp - Part Two\n";
	cout << Clamp2(12, 45, 78) << endl;
	cout << Clamp2(23, 34, 30) << endl;
	cout << Clamp2(1, 10, -12) << endl;

	cout << "\n";

	// 3.) HIGH AND LOW GAME
	cout << "High and Low Game\n";
	HighLowGame();

	cout << "\n";

	// 4.) TO UPPER OR TO LOWER
	cout << "To Upper\n";
	cout << ToUpper('q') << endl;
	cout << ToUpper('r') << endl;
	cout << ToUpper('a') << endl;
	cout << ToUpper('!') << endl;

	cout << "\n";
	cout << "ToLower\n";
	cout << ToLower('E') << endl;
	cout << ToLower('X') << endl;
	cout << ToLower('S') << endl;
	cout << ToLower('#') << endl;

	cout << "\n";

	// 5.) UNIT TESTING FRAMEWORK

	// Pauses the system and waits for user input
	system("pause");

	return 0;
}

int Sum(int x, int y) // 2.) Declaring and Defining Functions
{
	// Adds the x and y parameters
	int sum = x + y;

	// Prints out the sum to the console
	//cout << "The sum of your numbers are: " << sum << endl;

	return sum;
}

/** CLOSED ACTIVITIES **/

// 1.) Function Prototypes
void HelloFunctions()
{
	// Prints 'Hello Functions' out to the console
	cout << "Hello Functions" << endl;
}

int Square(int x)
{
	// Squares the value and sets it to x
	x *= x;

	// return x
	return x;
}

float Decimal(int x, int y)
{
	// casts the ints to floats and divides them to make them a decimal
	float decimal = (float)x / (float)y;

	// return decimal
	return decimal;
}

float Difference(float x, float y, float z)
{
	// Calculates the Difference between x and y
	float dif1 = x - y;
	// Checks to see if the difference is negative
	if (dif1 < 0.0f)
		// if it is multiply it by -1 to make it positive
		dif1 *= -1.0f;

	// Calculates the difference between y and z
	float dif2 = y - z;
	// Checks to see if the difference is negative
	if (dif2 < 0.0f)
		// if it is multiply it by -1 to make it positive
		dif2 *= -1.0f;

	// Calculates the difference between x and z
	float dif3 = x - z;
	// Checks to see if the difference is negative
	if (dif3 < 0.0f)
		// if it is multiply by -1 to make it positive
		dif3 *= -1;

	// Checks to see if dif1 is the largest difference
	if (dif1 > dif2 && dif1 > dif3)
		// if it is dif1 is returned
		return dif1;
	// Checks to see if dif2 is the largest difference
	else if (dif2 > dif1 && dif2 > dif3)
		// if it is dif2 is returned
		return dif2;
	// If the above conditions aren't true dif3 must be the largest difference
	else
		// returns dif3
		return dif3;	
}

// 2.) Functions Definitions
void Coordinates(int x, int y)
{
	// Prints x and y out as coordinates (x, y)
	printf("%d,%d\n", x, y);
}

// 3.) Sum of 3 Integers
int Sum(int x, int y, int z)
{
	// Adds all variables and puts them into sum
	int sum = x + y + z;

	// Returns sum
	return sum;
}

/** OPEN ACTIVITIES **/

// 1.) Min
int Min(int x, int y)
{
	// Checks to see if x is less than y
	if (x < y)
		// if it is return x
		return x;
	// if it's not return y
	else
		return y;
}

// 2.) Max
int Max(int x, int y)
{
	// Checks to see if x is greater than y
	if (x > y)
		// if it is return x
		return x;
	// if it's not return y
	else
		return y;
}

// 3.) Clamp
int Clamp(int x, int y, int z)
{
	// Checks to see if z is less than x
	if (z < x)
		// if it is z is set to x
		z = x;
	// Checks to see if z is greater than y
	else if (z > y)
		// if it is z is set to y
		z = y;
	
	// Return z
	return z;
}

// 4.) Distance
float Distance(int xA, int yA, int xB, int yB)
{
	// Subtrace the x coordinates
	float xPoints = xB - xA;
	// Square the x coordinates
	xPoints = Square(xPoints);

	// Subtract the y coordinates
	int yPoints = yB - yA;
	// Square the y coordinates
	yPoints = Square(yPoints);

	// Calculates the square root (float function) of the sum of the previous calculations
	float distance = sqrtf((float)xPoints + (float)yPoints);

	// Return distance
	return distance;
}

// 5.) Estimated Time Of Arrival
int ETA(int xA, int yA, int xB, int yB, int speed)
{
	// Get the distance between the points
	int dist = Distance(xA, yA, xB, yB);

	// Divide the distance by the speed
	int eTA = dist / speed;

	// Return eTA
	return eTA;
}

/** CHALLENGE ACTIVITIES **/

// 1.) LINEAR INTERPOLATION
float Lerp(int x, int y, float z)
{
	int lerpVal = 0;
	// Adds the x and y values so the z variable can represent a percentage
	int xAndYSum = Sum(x, y);

	// Clamps z between 1 and 0
	if (z < 0.0f)
		z = 0.0f;
	else if (z > 1.0f)
		z = 1.0f;

	// Calculates the percentage of the sum of x and y that z represents
	float lerpValue = (float)xAndYSum * z;

	// Checks to see if the value is greater than 1
	if (lerpValue >= 1.0f)
	{
		// if it is get rid of the decimal values by casting to int
		lerpVal = (int)lerpValue;
		// ... then return the int by casting back to a float, the printf formatting will take care of the 0's after the decimal
		return (float)lerpVal;
	}
	else
		// if the value is less than one return the original float
		return lerpValue;
}

// 2.) CLAMP - PART TWO
int Clamp2(int x, int y, int z)
{
	// Set the minimum value in the range
	int min = Min(x, y);

	// Set the maximum value in the range
	int max = Max(x, y);

	// Set z to the min range value if it's less than the min value
	if (z < min)
		z = min;
	// Set z to the max range value if it's more than the max value
	else if (z > max)
		z = max;

	// Always return z
	return z;
}

// 3.) HIGH AND LOW GAME
void HighLowGame()
{
	// Seeding the rand() function to get a random number
	srand(time(nullptr));

	// The intial random number for the player to guess (Between 1 - 50)
	int randNum = rand() % 50 + 1;
	// The player's guess
	int userGuess = 0;
	// The player's tries
	int tries = 3;
	// The player's answer if they want to play again.
	char playAgain = 'n';

	// Simple do, while loop used as a game loop. The loop is tested against how many tries the player has left as the exit condition.
	do
	{
		// Prompt the player to guess a number between 1 and 50
		cout << "Guess A Number Between 1 and 50: ";
		// Take the player's guess
		cin >> userGuess;

		// Test the players guess
		if (userGuess == randNum)
		{
			cout << "You guessed the number!\n";
			// The player guessed the number so, we break out of the game loop
			break;
		}
		else if (userGuess < randNum)
		{
			// Prompts the user that their guess was too low
			cout << "Too Low!\n";
			// Takes a try away
			tries--;
		}
		else
		{
			// Prompts the user that their guess was too high
			cout << "Too High!\n";
			// Takes a try away
			tries--;
		}

		// Checks to see if the user has any more guesses
		if (tries <= 0)
		{
			// If there are no more guesses, prompts the user that they lost and asks if they want to play again
			cout << "Sorry you lose!\n" << "The number was " << randNum << "\nDo you want to play again? (y or n): ";
			// Takes the user's input
			cin >> playAgain;

			// Tests the user's input.
			switch (playAgain)
			{
			// The player wants to play again.
			case 'y':
			case 'Y':
				// Prompt to let the player know the game is restarting
				cout << "Awesome! Here we go!\n";
				// Gives a new random number
				randNum = rand() % 50 + 1;
				// Resets the tries
				tries = 3;
				break; // Breaks out of switch case statement NOT the game loop
			// The player doesn't want to play again
			case 'n':
			case 'N':
				// Prompt thanking the player for playing the game
				cout << "Ok! Thanks for playing!\n";
				break; // Breaks out of the switch case statement NOT the game loop
			default:
				// Prompts the player that they didn't make a valid choice, and the game will end. Thanks the player for playing.
				cout << "You didn't make a valid choice, so I'll end the game. Thanks for playing!\n";
				break; // Breaks out of the switch case statement NOT the game loop
			}
		}
	} while (tries > 0); // The exit condition for the do, while game loop. Used do, while because I want the loop to execute at least once.
}

// 4.) TO UPPER OR TO LOWER
char ToUpper(char x)
{
	/* Switch case statement checks the user's input, replaces it with the capital version of the char, and returns it. 
	   Any character that isn't a letter will just return that same character as the default case just breaks the switch 
	   case statement. The variable x is always returned. */
	switch (x)
	{
	case 'a':
		x = 'A';
		break;
	case 'b':
		x = 'B';
		break;
	case 'c':
		x = 'C';
		break;
	case 'd':
		x = 'D';
		break;
	case 'e':
		x = 'E';
		break;
	case 'f':
		x = 'F';
		break;
	case 'g':
		x = 'G';
		break;
	case 'h':
		x = 'H';
		break;
	case 'i':
		x = 'I';
		break;
	case 'j':
		x = 'J';
		break;
	case 'k':
		x = 'K';
		break;
	case 'l':
		x = 'L';
		break;
	case 'm':
		x = 'M';
		break;
	case 'n':
		x = 'N';
		break;
	case 'o':
		x = 'O';
		break;
	case 'p':
		x = 'P';
		break;
	case 'q':
		x = 'Q';
		break;
	case 'r':
		x = 'R';
		break;
	case 's':
		x = 'S';
		break;
	case 't':
		x = 'T';
		break;
	case 'u':
		x = 'U';
		break;
	case 'v':
		x = 'V';
		break;
	case 'w':
		x = 'W';
		break;
	case 'x':
		x = 'X';
		break;
	case 'y':
		x = 'Y';
		break;
	case 'z':
		x = 'Z';
		break;
	default:
		break;
	}

	return x;
}

char ToLower(char x)
{
	/* Switch case statement checks the user's input, replaces it with the lower case version of the char, and returns it.
	Any character that isn't a letter will just return that same character as the default case just breaks the switch case 
	statement. The variable x is always returned. */
	switch (x)
	{
	case 'A':
		x = 'a';
		break;
	case 'B':
		x = 'b';
		break;
	case 'C':
		x = 'C';
		break;
	case 'D':
		x = 'd';
		break;
	case 'E':
		x = 'e';
		break;
	case 'F':
		x = 'f';
		break;
	case 'G':
		x = 'g';
		break;
	case 'H':
		x = 'h';
		break;
	case 'I':
		x = 'i';
		break;
	case 'J':
		x = 'j';
		break;
	case 'K':
		x = 'k';
		break;
	case 'L':
		x = 'l';
		break;
	case 'M':
		x = 'm';
		break;
	case 'N':
		x = 'n';
		break;
	case 'O':
		x = 'o';
		break;
	case 'P':
		x = 'p';
		break;
	case 'Q':
		x = 'q';
		break;
	case 'R':
		x = 'r';
		break;
	case 'S':
		x = 's';
		break;
	case 'T':
		x = 't';
		break;
	case 'U':
		x = 'u';
		break;
	case 'V':
		x = 'v';
		break;
	case 'W':
		x = 'w';
		break;
	case 'X':
		x = 'x';
		break;
	case 'Y':
		x = 'y';
		break;
	case 'Z':
		x = 'z';
		break;
	default:
		break;
	}

	return x;
}

// 5.) UNIT TESTING FRAMEWORK
void FunctionTesting()
{
	// TODO

	/* Automated test systems are useful as a way to automatically check for regressions when updating your code to be more efficient or readable. Pure functions 
	   are the easiest to test in a C++ project since they do not generate side-effects or have external dependencies.

       Research other testing frameworks such as Google Test, FakeIt, or DocTest as a model for how other people have attempted to provide a solution before designing your own.

       Create a set of functions that you can use in the future to test your functions. The simplest approach tests the return value of a function against an expected value with 
	   respect to a set of inputs. */
}
