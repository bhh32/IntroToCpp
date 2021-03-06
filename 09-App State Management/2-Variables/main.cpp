#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	/* Closed Assignment Problems */ 
	
	/* Problem A (Guess Before Program Is Ran: 14) */
	int numberA = 5;

	numberA = 9;
	numberA = 11;
	numberA = 14;

	cout << "A) " << numberA << endl;

	/* Problem B (Guess Before Program Is Ran: 9) */
	int numberB = 10;
	numberB = 9;

	int thing = 55;
	thing = 22;

	cout << "B) " << numberB << endl;

	/* Problem C (Guess Before Program Is Ran: 21) */
	int numberC = 3;
	numberC = 7;
	numberC = 1;

	int somethingC = 23;
	somethingC = 21;

	numberC = somethingC;

	cout << "C) " << numberC << endl;

	/* Problem D (Guess Before Program Is Ran: 3) */
	int numberD = 1;
	int somethingD = 3;

	numberD = somethingD;

	cout << "D) " << somethingD << endl;

	/* Problem E (Guess Before Program Is Ran: 6)*/
	int x = 13;

	x = x / 2;

	cout << "E) " << x << endl;

	/* Problem F (Guess Before Program Is Ran: 6.5) */
	float y = 13;

	y = y / 2;

	cout << "F) " << y << endl;

	// Skip a line
	cout << "\n";

	/* Celsius to Fahrenheit */
	float degCelsius = 78.0f;
	float degFahrenheight = 0.0f;

	// My Work
	degFahrenheight = (degCelsius * 1.8f) + 32.f;

	// Given Print To Console Code
	cout << "Celsius to Fahrenheit)" << endl;
	cout << "Celsius: " << degCelsius << endl;
	cout << "Fahrenheit: " << degFahrenheight << endl;

	// Skip a Line
	cout << "\n";

	// Have the user enter a value for deg celsius to convert
	cout << "Enter a value in deg celsius to convert to fahrenheit: ";
	cin >> degCelsius;

	// Convert to fahrenheight
	degFahrenheight = (degCelsius * 1.8f) + 32.f;

	// Print out the converstion
	cout << "The temp converted is: " << degFahrenheight << endl;

	// Skip a line
	cout << "\n";

	/* Area of a Rectangle */
	float rectWidth = 0.0f;
	float rectHeight = 0.0f;
	float rectArea = 0.0f;

	// My Work
	rectWidth = 4.5f;
	rectHeight = 5.5f;
	rectArea = rectWidth * rectHeight;

	// Given Print To Console Code
	cout << "Area of a Rectangle)" << endl;
	cout << "Height: " << rectHeight << " , Width: " << rectWidth << endl;
	cout << "Area: " << rectArea << endl;

	// Skip a line
	std::cout << "\n";

	// Get User Input
	cout << "Enter A Height: ";
	cin >> rectHeight;
	cout << "\n";
	cout << "Enter A Width: ";
	cin >> rectWidth;

	// Calculate the new area
	rectArea = rectWidth * rectHeight;

	// Print out the area of the users rectangle
	cout << "Your Rectangle Area Is: " << rectArea << endl;

	// Skip a line
	cout << " " << endl;

	/* Average of Five */
	float a, b, c, d, e; // Modify these variables below.
	float avg;           // Modify these variables below.

	avg = a = b = c = d = e = 0.0f;

	// My Work
	bool allNumsEntered = false;
	do
	{
		cout << "Enter a decimal number higher than 0.0: ";
		if (a == 0.0f)
			cin >> a;
		else if (b == 0.0f)
			cin >> b;
		else if (c == 0.0f)
			cin >> c;
		else if (d == 0.0f)
			cin >> d;
		else if (e == 0.0f)
		{
			cin >> e;
			avg = (a + b + c + d + e) / 5.0f;
			allNumsEntered = true;
		}

		// Skip a line
		cout << "\n";

	} while (!allNumsEntered);

	// Print the average of the user's input numbers to the console
	cout << "The average of the numbers you entered is: " << avg << endl;

	// Skip a line
	cout << "\n";

	/* Number Swap */
	int firstNum = 13;
	int secondNum = 24;

	/* My Work */
	// The variables initial values printed out to the console
	cout << "Number Swap Initial Values" << endl;
	cout << "firstNum is: " << firstNum << endl;
	cout << "secondNum is: " << secondNum << endl;

	//Skip a line
	std::cout << "\n";

	// Create a temp variable to hold the secondNum value
	int temp = secondNum;
	// Put the firstNum value into the secondNum variable
	secondNum = firstNum;
	// Put the temp variables value (secondNum's original value) into the firstNum variable
	firstNum = temp;

	/* Given Print To Console Code */
	// Print out the number swap program title and variables swapped values
	cout << "Number Swap)\n";
	cout << "firstNum is: " << firstNum << endl;
	cout << "secondNum is: " << secondNum << endl;

	// Skip a line
	std::cout << "\n";

	/* Fun Facts for Your Age */
	int age = 0;

	// My Work
	std::cout << "Please Enter Your Age: ";
	std::cin >> age;

	// Tell the user how old they are
	cout << "Howdy! You are " << age << " years old!\n";

	// Calculate The Months The User Has Been Alive Approx.
	int months = age * 12;
	cout << "You've been alive for at least " << months << " months!\n";

	// Calculate The Decades The User Has Been Alive
	float decades = 0.0f;
	decades = (float)age / 10.0f;
	cout << "You have been alive for " << decades << " decades!\n";

	// Calculate The Scores The User Has Been Alive
	float scores = 0.0f;
	scores = (float)age / 20.0f;
	cout << "You have been alive for " << scores << " scores! *Note: A score is 20 years.\n";

	int japanLifeExp = 84;

	if (age > japanLifeExp)
		cout << "You have gone over the life expectancy of Japan, which is: " << japanLifeExp << endl;
	else if (age == japanLifeExp)
		cout << "You are the same age as the life expectancy of Japan, which is: " << japanLifeExp << endl;
	else
	{
		japanLifeExp -= age;
		cout << "You are " << japanLifeExp << " years from Japan's life expectancy of 84 years old!\n";
	}

	int usLifeExp = 79;

	if (age > usLifeExp)
		cout << "You have gone over the life expectancy of the U.S., which is: " << usLifeExp << endl;
	else if (age == usLifeExp)
		cout << "You are the same age as the U.S.'s life exectancy: " << usLifeExp << endl;
	else
	{
		usLifeExp -= age;
		cout << "You are " << usLifeExp << " years from the U.S.'s life expectancy of 79 years old!\n";
	}

	int sierraLeoneLifeExp = 50;

	if (age > sierraLeoneLifeExp)
		cout << "You have gone over the life expectancy of Sierra Leone, which is " << sierraLeoneLifeExp << endl;
	else if (age == sierraLeoneLifeExp)
		cout << "You are the same age as the Sierra Leone Life expectancy: " << sierraLeoneLifeExp << endl;
	else
	{
		sierraLeoneLifeExp -= age;
		cout << "You are " << sierraLeoneLifeExp << " years from Sierra Leone's life expectancy of 50 years old!\n";
	}

	// Skip a line
	std::cout << "\n";


	/** Challenge **/

	/* Conforming To Conventions - Lower Camel Case To Lower Snake Case */
	// Lower Camel Case              ** Lower Snake Case
	// int age;                         // int age;
	// int bulletCount;                 // int bullet_count;
	// float dogYears;                  // float dog_years;
	// int qty;                         // int qty;
	// float shieldValue;               // float shield_value;
	// float redArmorRatio;             // float red_armor_ratio;
	// int happiness;                   // int happiness;
	// int gandhiAggression;            // int gandhi_aggression;


	/* The Right Tool for the Job */
	// int num;                // integer
	// float num2;             // single precision floating point
	// double num3;            // double precision floating point
	// bool boolean;           // Boolean
	// char character;         // Character
	// void f(int);            // void type - Checks if void is true or false
	// long double num4;       // Long Double more than double precision floating point
	// unsigned int num5;      // Unsigned Integer
	// signed int num6;        // Signed Integer
	// short int num7;         // Short Integer
	// long int num8;          // Long Integer
	// long long int num9;     // Long Long Integer

	/* Number Swap (Difficulty Up) */
	
	// My Work
	// Print the initial values out to the console using the swapped numbers from the previous swap
	cout << "Number Swap (Difficulty Up)\n";
	cout << "firstNum: " << firstNum << endl;
	cout << "secondNum: " << secondNum << endl;

	// firstNum subtracts 11 to get 13 as the value, completing the first part of the "swap" of the values
	firstNum -= 11;
	// secondNum adds 11 to get 24 as the value, thus completing the "swapping" of the values
	secondNum += 11;

	// Skip a line
	cout << "\n";

	// Print the Swapped values out to the console
	cout << "firstNum swapped value: " << firstNum << endl;
	cout << "secondNum swapped value: " << secondNum << endl;

	// Skip a line
	cout << "\n";


	/**
	// Creating and Assigning to Variables //

	// Define an integer variable
	int num1 = 1;

	// Print out the value of the int variable
	std::cout << "Initial value: " << num1 << std::endl;

	// Reassign the value of the integer
	num1 = 2;

	// Print out the value of the reassigned int variable
	std::cout << "Reassigned value: " << num1 << std::endl;

	//for loop to reassign values to num1 and print them out
	for (int i = 3; i < 6; i++)
	{
		// Reassign the value to the value of i
		num1 = i;
		// Print the newly reassigned value of num1 to the console
		std::cout << "New Reassigned value: " << num1 << std::endl;
	}

	// Skip a line
	std::cout << " " << std::endl;

	// Using Arithmetic Operators on Integer Variables //

	// Instantiate two new variables with distinct names
	int var1 = 1;
	int var2 = 2;

	// Instantiate a third integer variable whose value is equal to the sum of var1 and var2
	int varSum = var1 + var2;

	// Print the value of varSum
	std::cout << "The sum of var1 and var2: " << varSum << std::endl;

	// Skip a line
	std::cout << " " << std::endl;

	// Repeat the previous steps with using fractional values in the first two variables
	var1 = 2.3;
	var2 = 5.2;

	varSum = var1 + var2;

	std::cout << "The reassigned variable fractional values sum: " << varSum << std::endl;

	// Skip a line
	std::cout << " " << std::endl;

	// Using Aritmetic Operators on Floating-Point Variables //
	float flt1 = 12.3f;
	float flt2 = 65.2f;

	float fltSum = flt1 + flt2;

	std::cout << "The sum of flt1 and flt2: " << fltSum << std::endl;

	// Skip a line
	std::cout << " " << std::endl;

	// Repeat the previous steps using whole number values for the variables
	flt1 = 12;
	flt2 = 56;

	fltSum = flt1 + flt2;

	std::cout << "The reassigned variable whole number values sum: " << fltSum << std::endl;

	// Skip a line
	std::cout << " " << std::endl;

	// Storing User Input in Integer Variables //
	int userInput = 0;

	// Ask the user for a whole number
	std::cout << "Enter a whole number: ";

	// Store the user's input into the userInput int variable
	std::cin >> userInput;

	// Print out the user's input
	std::cout << "Your number was: " << userInput << std::endl;

	// Skip a line
	std::cout << " " << std::endl;
	**/

	// Pause the system until the user presses a key
	system("pause");

	// End the program
	return 0;
}