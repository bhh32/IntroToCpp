#ifndef MATHUTILS_H
#define MATHUTILS_H
#pragma once

class MathUtils
{
public:
	// Returns the less of two integers
	int Min(int a, int b);

	// Returns the greater of two integers
	int Max(int a, int b);

	// Returns a value clamped within a range
	int Clamp(int lower, int upper, int value);

	// Returns the distance between two points
	int Dist(int x1, int y1, int x2, int y2);

	// Returns the square of the numbers
	int Square(int x);
};
#endif MATHUTILS_H
