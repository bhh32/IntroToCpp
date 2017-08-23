#include "vector2.h"
#include <iostream>

using std::cout;

void Vector2DSum(float x1, float x2, float y1, float y2)
{
	float xVector = x1 + x2;
	float yVector = y1 + y2;

	cout << "The sum of your two Vectors is: " << xVector << "," << yVector << "\n";
}

void Vector2DDiff(float x1, float x2, float y1, float y2)
{
	float xVector = x1 - x2;
	float yVector = y1 - y2;

	cout << "The difference of your two Vectors is: " << xVector << "," << yVector << "\n";
}

float Vector2DDist(float x1, float x2, float y1, float y2)
{
	float xVector = (x2 - x1) * (x2 - x1);
	float yVector = (y2 - y1) * (y2 - y1);
	float dist = sqrt(xVector + yVector);

	return dist;
}