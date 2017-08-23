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
void StudentInformation(students kids);
float StudentAverageScore(students section[], int size);
int StudentMedianScore(students section[], int size);
void TotalNumberStusInCourse(students section[], int courseNum);

#endif STUDENT_H
