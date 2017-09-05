#include <iostream>
#include "func.h"
#include "mathutils.h"
#include "dtgreet.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	/** WALKTHROUGH **/
	Func func;
	cout << "Walkthrough Activities\n";
	cout << "The sum of 12 and 4 is: " << func.Sum(12, 4) << endl;

	cout << "\n";

	/** CLOSED ACTIVITIES **/
	MathUtils math;
	cout << "Closed Activities\n";

	// Min Function Test
	cout << "Min Function Test\n";
	cout << "The lower number between 23 and 56 is: " << math.Min(23, 56) << endl;
	cout << "The lower number between 85 and 46 is: " << math.Min(85, 46) << endl;
	
	cout << "\n";

	// Max Function Test
	cout << "Max Function Test\n";
	cout << "The larger number between 23 and 56 is: " << math.Max(23, 56) << endl;
	cout << "The larger number between 85 and 46 is: " << math.Max(85, 46) << endl;

	cout << "\n";

	// Clamp Function Test
	cout << "Clamp Function Test\n";
	cout << "20 Clamped to the range of 23 and 56 is: " << math.Clamp(23, 56, 20) << endl;
	cout << "100 Clamped to the range of 45 and 90 is: " << math.Clamp(45, 90, 100) << endl;
	cout << "50 Clamped to the range of 27 and 89 is: " << math.Clamp(27, 89, 50) << endl;

	cout << "\n";

	// Distance Function Test
	cout << "Distance Function Test\n";
	cout << "The distance between (23, 34) and (12, 3) is: " << math.Dist(23, 34, 12, 3) << endl;
	cout << "The distance between (12, 4) and (1, 8) is: " << math.Dist(12, 4, 1, 8) << endl;
	cout << "The distance between (9, 43) and (53, 100) is: " << math.Dist(9, 43, 53, 100) << endl;

	cout << "\n";

	// Square Function Test
	cout << "Square Function Test\n";
	cout << "The square of 4 is: " << math.Square(4) << endl;
	cout << "The square of 8 is: " << math.Square(8) << endl;
	cout << "The square of 12 is: " << math.Square(12) << endl;

	cout << "\n";

	/** OPEN ACTIVITIES **/
	DateTimeGreeting dt;
	cout << "OPEN ACTIVITIES\n";

	// Day Greeting Function Test
	cout << "Day Greeting Function Test\n";
	dt.DayGreeting(8, 16, 2017);
	dt.DayGreeting(3, 12, 2020);

	cout << "\n";

	// Time Greeting Function Test
	cout << "Time Greeting Function Test\n";
	dt.TimeGreeting(11, 21);
	dt.TimeGreeting(12, 56);
	dt.TimeGreeting(24, 04);

	cout << "\n";

	// Is Leap Year Function Test
	cout << "IsLeapYear Function Test\n";
	bool leapYearTest1 = false;
	bool leapYearTest2 = false;
	bool leapYearTest3 = false;
	bool leapYearTest4 = false;
	int testComplete = 4;

	leapYearTest1 = dt.IsLeapYear(2017);
	leapYearTest2 = dt.IsLeapYear(2016);
	leapYearTest3 = dt.IsLeapYear(2018);
	cout << /*leapYearTest4 =*/ dt.IsLeapYear(2020) << endl;

	// Figure Above Out Later

	cout << "\n";

	/** RANDOM NUMBER GENERATORS **/



	system("pause");

	return 0;
}