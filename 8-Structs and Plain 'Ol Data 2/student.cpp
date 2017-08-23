#include <iostream>
#include "student.h"

using std::cout;
using std::cin;

void StudentInformation(students kids)
{
	cout << "Student ID: " << kids.studentID << " Enrolled Course: " << kids.courseNumber << " Last Exam Score: " << kids.lastExamScore << "\n";
}

float StudentAverageScore(students section[], int size)
{
	float total = 0.0f;

	for (int i = 0; i < size; ++i)
	{
		total += section[i].lastExamScore;
	}

	return  total / size;
}

int StudentMedianScore(students section[], int size)
{
	while (true)
	{
		bool isSorted = true;
		for (int i = 0; i < size - 1; ++i)
		{
			// is the adjacent value smallest than my current value?
			if (section[i].lastExamScore < section[i + 1].lastExamScore)
			{
				// if so, let's swap them
				students temp = section[i]; // holds the original

				section[i] = section[i + 1]; // puts the second index into the first
				section[i + 1] = temp; // puts the first index into the second

				isSorted = false;
			}
		}

		if (isSorted)
			break;
	}

	// getting the median
	if (size % 2 == 0)
	{
		int midIdx = size / 2;
		int lhs = section[midIdx - 1].lastExamScore;
		int rhs = section[midIdx].lastExamScore;

		return (lhs + rhs) / 2;
	}
	else
	{
		return section[size / 2].lastExamScore;
	}
}

void TotalNumberStusInCourse(students section[], int courseNum)
{
	int courseCount = 0;
	for (int i = 0; i < 6; i++)
	{
		if (section[i].courseNumber == courseNum)
		{
			courseCount++;
		}
	}

	cout << "There are " << courseCount << " kids in Course Number " << courseNum << ".\n";
}