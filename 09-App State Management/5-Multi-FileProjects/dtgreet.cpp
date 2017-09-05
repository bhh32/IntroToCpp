#include <iostream>
#include "dtgreet.h"

using std::cout;
using std::endl;

void DateTimeGreeting::DayGreeting(int day, int month, int year)
{
	if (day < 32 && day >= 0 && month <= 12 && month > 0 && year > 1899)
		printf("Today is (day/month/year): %d\\%d\\%d\n", day, month, year);
	else
		printf("You didn't enter a valid year\n");
}

void DateTimeGreeting::TimeGreeting(int hour, int minute)
{
	// Allows for World Time Clock (Military Time)
	if (hour <= 24 && minute < 60)
		printf("The time is: %d:%d\n", hour, minute);
	else
		printf("You didn't enter a valid time\n");
}

bool DateTimeGreeting::IsLeapYear(int year)
{
	bool isLeapYear = false;
	
	if (year % 4 == 0)
	{
		if(year % 100)
			isLeapYear = !isLeapYear;
	}
	else
		isLeapYear = false;

	return isLeapYear;
}
