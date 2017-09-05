#ifndef DTGREET_H
#define DTGREET_H
#pragma once

class DateTimeGreeting
{
public:
	// Prints a greeting to the console based on day, month, and year.
	void DayGreeting(int day, int month, int year);

	// Prints a greeting to the console based on the time
	void TimeGreeting(int hour, int minute);

	// Determines whether or not a given year is a leap year or a common year
	bool IsLeapYear(int year);

};
#endif DTGREET_H
