#include "mathutils.h"
#include <cmath>

// Returns the less of two integers
int MathUtils::Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

// Returns the greater of two integers
int MathUtils::Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

// Returns a value clamped within a range
int MathUtils::Clamp(int lower, int upper, int value)
{
	int min = Min(lower, upper);
	int max = Max(lower, upper);

	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	
	return value;
}

// Returns the distance between two points
int MathUtils::Dist(int x1, int y1, int x2, int y2)
{
	int pointX = Square((x2 - x1));
	int pointY = Square((y2 - y1));

	int distance = sqrt(pointX + pointY);

	return distance;
}

// Returns the square of the numbers
int MathUtils::Square(int x)
{
	return x * x;
}