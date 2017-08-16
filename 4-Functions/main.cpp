#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Sum(int x, int y); // 1.) Declaring and Defining Functions

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

	// Pauses the system and waits for user input
	system("pause");

	return 0;
}

void Sum(int x, int y) // 2.) Declaring and Defining Functions
{
	// Adds the x and y parameters
	int sum = x + y;

	// Prints out the sum to the console
	cout << "The sum of your numbers are: " << sum << endl;
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
	// TODO
	/* Define a function that accepts three numbers, where the first two describe the beginning and end of a range respectively.
	The third value is a normalized number that ranges between 0 to 1. The third number is used to pick a value within the range.
    For example, if the numbers 2, 4, and 0.5 are provided, then the number 3 would be returned. You can think of 0.5 as being 
    50% or halfway between 2 and 4. */
}

// 2.) CLAMP - PART TWO
int Clamp2(int x, int y, int z)
{
	// TODO
	/* Did you reuse the min and max function when you implemented your clamp function? If you didn’t, try doing so now! 
	Your clamp function should not include anything other than function calls and number literals. */
}

// 3.) HIGH AND LOW GAME
void HighLowGame()
{
	// TODO
	/* Add functionality to your program that provides the user with three to five opportunities to guess a secret number. 
	   The player guesses by providing a number which is said to be too high, too low, or on the mark with respect to the secret number.

       Remember to provide feedback to the player by printing a message for each guess.

       Use a random number generator such as rand() to generate a random number for your secret number. Remember to seed the random number 
	   generator with srand() if that’s what you’ll be using. */
}

// 4.) TO UPPER OR TO LOWER
char ToUpper(char x)
{
	// TODO

	/* Programming libraries such as humanizer serve as tools to format text in a manner that conforms to the given conventions for a particular use-case. 
	   For example, the US National Weather Service (NWS) broadcasts parts of their weather advisories in all uppercase letters.

       ...SMALL CRAFT ADVISORY FOR WINDS IN EFFECT UNTIL 9 PM CDT THIS EVENING...
       Example of a Weather Advisory from NOAA

       Rather than manually process each line and capitalize it in a manner befitting for consumption by humans, you could put it through a program instead!

       Research and apply concepts from the ASCII table to create functions that convert a single character value into its uppercase or lowercase equivalent. */
}

char ToLower(char x)
{
	// TODO

	/* Programming libraries such as humanizer serve as tools to format text in a manner that conforms to the given conventions for a particular use-case.
	For example, the US National Weather Service (NWS) broadcasts parts of their weather advisories in all uppercase letters.

	...SMALL CRAFT ADVISORY FOR WINDS IN EFFECT UNTIL 9 PM CDT THIS EVENING...
	Example of a Weather Advisory from NOAA

	Rather than manually process each line and capitalize it in a manner befitting for consumption by humans, you could put it through a program instead!

	Research and apply concepts from the ASCII table to create functions that convert a single character value into its uppercase or lowercase equivalent. */
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
