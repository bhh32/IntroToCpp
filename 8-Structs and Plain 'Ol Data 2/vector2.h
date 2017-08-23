#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H

struct vector2
{
public:
	// variables
	float x = 0.f;
	float y = 0.f;

};

// functions
void Vector2DSum(float x1, float x2, float y1, float y2);
void Vector2DDiff(float x1, float x2, float y1, float y2);
float Vector2DDist(float x1, float x2, float y1, float y2);

#endif VECTOR2_H
