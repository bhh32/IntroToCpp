#pragma once
#ifndef STUDENT_H
#define STUDENT_H

struct students
{
	// Variables
	int studentID;
	int courseNumber;
	int lastExamScore;
	

};

// Functions
void StudentInformation(int id, int courseNum, int lastExamScore);
float StudentAverageScore(students section[], int size);
float StudentMedianScore(students section[], int size);
void TotalNumberStusInCourse(int courseNum);

#endif STUDENT_H
