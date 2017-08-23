#include <iostream>
#include "wallet.h"
#include "student.h"
#include "vector2.h"
#include "playervszombie.h"

using std::cout;

int main()
{
	cout << "Closed Activities\n";
	piggybank piggy;

	float bills = calcPiggybankNotes(piggy);
	float coins = calcPiggybankCoins(piggy);
	float total = calcPiggybankTotal(piggy);

	cout << "$" << bills << "\n";
	cout << "$" << coins << "\n";
	cout << "$" << total << "\n";

	cout << "\n";

	cout << "Open Activities\n";

	/*students kids;
	StudentInformation(kids.studentID, kids.courseNumber, kids.lastExamScore);*/

	students lastExamScore
	{
		45,
		29,
		32
	};

	cout << "\n";

	//StudentAverageScore(students section[], int size);
	//StudentMedianScore();
	TotalNumberStusInCourse(2);
	TotalNumberStusInCourse(1);

	cout << "\n";

	cout << "Vector2D\n";
	vector2 vector2d;
	Vector2DSum(2, 5, 3, 10);
	Vector2DDiff(5, 3, 2, 20);
	cout << "The distance between your vectors is: " << Vector2DDist(6, 12, 43, 7) << " units\n";

	cout << "Player VS. Zombie\n";
	Battle();
	
	system("pause");

	return 0;
}