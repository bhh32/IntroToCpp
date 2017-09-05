#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	/** Closed Activity **/
	// 1.) TRUTH TABLES 

	 // 1.) true AND true = true
	 // 2.) true OR false = true
	 // 3.) false OR true = true
	 // 4.) false AND true = false
	 // 5.) true AND false = false
	 // 6.) false OR true OR false = true
	 // 7.) true AND (true OR false) = true

	// 2.) Evaluate the Following

	// Problem A **Guess Before Program Ran: 30
	int numberA = 15;
	if (numberA > 10)
	{
		numberA = numberA * 2;
	}

	cout << "A) " << numberA << endl;

	// Problem B **Guess Before Program Ran: 15
	int numberB = 15;
	if (numberB < 15)
	{
		numberB = numberB * 3;
	}

	cout << "B) " << numberB << endl;

	// Problem C **Guess Before Program Ran: 24
	int numberC = 12;
	if (numberC == 12)
	{
		numberC = numberC * 2;
	}

	cout << "C) " << numberC << endl;

	// Problem D **Guess Before Program Ran: 0
	int numberD = 12;
	if (numberD <= 12)
	{
		numberD = numberD * 0;
	}

	cout << "D) " << numberD << endl;

	// Problem E **Guess Before Program Ran: 56
	int numberE = 14;
	if (numberE >= 12)
	{
		numberE *= 4;
	}

	cout << "E) " << numberE << endl;

	// Problem F **Guess Before Program Ran: 6
	int numberF = 6;
	if (numberF == 0)
	{
		numberF = 0;
	}
	else if (numberF > 10)
	{
		numberF = 1;
	}

	cout << "F) " << numberF << endl;

	// Problem G **Guess Before Program Ran: 3
	int numberG = 6;

	if (numberG < 0)
	{
		numberG = 0;
	}
	else if (numberG < 2)
	{
		numberG = 1;
	}
	else if (numberG < 5)
	{
		numberG = 2;
	}
	else
	{
		numberG = 3;
	}
	cout << "G) " << numberG << endl;

	// Skip a line
	cout << "\n";

	// 2.) NUMBER JUDGING
	int userChoice = 0;

	// Prompt the user
	cout << "Enter a number between 1 and 100: ";
	// Take the user's input
	cin >> userChoice;

	// Skip a line
	cout << "\n";

	// Branch executes depending on
	if (userChoice > 50 && userChoice <= 100)
		cout << "Your number was " << userChoice << " and it is a larger number!\n";
	else if (userChoice < 50 && userChoice >= 1)
		cout << "Your number was " << userChoice << " and it is a smaller number!\n";
	else if (userChoice == 50)
		cout << "Your number was " << userChoice << " and it is a balanced number!\n";
	else
		cout << "You didn't choose a valid number.\n";

	// Skip a line
	cout << "\n";

	// 3.) AGE GATE
	int age = 0;

	// Prompt the user for their age
	cout << "Enter your age, please: ";
	cin >> age;

	// Skip a line
	cout << "\n";

	// Checks the age of the user and prints the appropriate message.
	if (age < 18 && age > -1)
		cout << "You are a minor.\n";
	else if (age > 18 && age < 50)
		cout << "You are an adult.";
	else if (age >= 50 && age < 65)
		cout << "You are an adult and eligible to join AARP!\n";
	else if (age >= 65)
		cout << "You are an adult and eligible for retirement benefits!\n";
	else
		cout << "You didn't enter a valid age!\n";

	cout << "\n";

	 // 4.) THE SMALLEST OF THREE NUMBERS
	 // Decalare and Initialize an array of 3 elements to hold the user input
	int choices[] = { 0, 0, 0 };
	
	// Get user input
	while (choices[2] == 0)
	{
		cout << "Please Enter A Number Greater Than 0: ";
		
		if (choices[0] == 0)
			cin >> choices[0];
		else if (choices[1] == 0 && choices[0] > 0)
			cin >> choices[1];
		else
			cin >> choices[2];
	}

	// Skip a line
	cout << "\n";

	// Check the user input for the largest value
	if (choices[0] < choices[1] && choices[0] < choices[2])
		cout << "The smallest number was: " << choices[0] << endl;
	else if (choices[1] < choices[0] && choices[1] < choices[2])
		cout << "The smallest number was: " << choices[1] << endl;
	else
		cout << "The smallest number was: " << choices[2] << endl;

	// Skip a line
	cout << "\n";

	/** OPEN ACTIVITY PROBLEMS **/
	// 1.) EVEN OR ODD

	float userChoose = 0.0f;
	bool even = false;

	cout << "Please Enter a Whole Number: ";
	cin >> userChoose;

	for (int i = 0; i <= 1000000000 ;i += 2)
	{
		if (i == userChoose)
		{
			even = true;
			break;
		}			
	}

	if (even)
		cout << "Your number is even!\n";
	else
		cout << "Your number is false!\n";

	cout << "\n";

	// 2.) CLAMP THE NUMBER

	float clampedNumber = 0.0f;

	cout << "Enter a number to clamp: ";
	cin >> clampedNumber;

	if (clampedNumber < 15.0f)
	{
		clampedNumber = 15.0f;
		cout << "Your clamped number is: " << clampedNumber << endl;
	}
	else if (clampedNumber > 30.0f)
	{
		clampedNumber = 30.0f;
		cout << "Your clamped number is: " << clampedNumber << endl;
	}
	else
		cout << "Your clamped number is: " << clampedNumber << endl;

	// Skip a line
	cout << "\n";

	// 3.) INPUT VALIDATION

	// Field:       Purchase Order for Cookies
	// Constraints: Must be ordered in multiples of 23. Only whole numbers.
	//              Round down to the nearest multiple if not a multiple of 23.
	//
	//              If nearest multiple is zero, provide an error message.

	int cookieOrder = 0;
	
	// Prompt the user to enter their order.
	cout << "Enter the number of cookies you'd like to order in multiples of 23: ";
	cin >> cookieOrder;

	for (int i = 1; i <= 1000000000; i++)
	{
		int temp = cookieOrder / 23;

		if (temp == temp % 23)
		{
			cout << "You ordered " << temp << " order of cookies!\n";
			break;
		}
		else
		{
			int temp2 = temp % 23;
			temp = cookieOrder - temp2;

			if (cookieOrder != 0)
			{
				cout << "You ordered " << temp << " order of cookies!\n";
				break;
			}
			else
			{
				cout << "You didn't order enough cookies!\n";
				break;
			}
		}
	}

	// Field:       Purchase Order for Sketchbooks (3pk)
	// Constraints: Must order at least 9 sketchbooks total.
	//              The total may not exceed 30 sketchbooks ordered.
	//
	//              If the total number of sketchbooks ordered does not meet
	//              the minimum order count or exceeds the maximum order count,
	//              provide an error message.

	int sketchbookOrder = 0;

	// Prompt the user to enter their order.
	cout << "Enter how many sketchbooks you want to order in multiples of 3. **Note: Minimum order is 9, and max order is 30.: ";
	cin >> sketchbookOrder;

	int orders = sketchbookOrder / 9;

	if (sketchbookOrder >= 9 && sketchbookOrder <= 30)
		cout << "You ordered " << orders << " packs of sketchbooks.\n";
	else if (sketchbookOrder < 9)
		cout << "You didn't meet the minimum order.\n";
	else
		cout << "You went over the maximum order.\n";
		

	// Field:       Enable Motion Blur
	// Constraints: Must be a 'y' or 'n' value.
	//
	//              Provide an error message if any other value.

	int y = 23;
	int n = 12;
	int userValue = 0;

	cout << "Enter either 23 or 12: \n";
	cin >> userValue;

	if (userValue == y || userValue == n)
		cout << "You entered " << userValue << ". Good job!\n";
	else
		cout << "You didn't follow directions!\n";


	// Field:       Texture Size
	// Constraints: Round to the nearest power of two. Only whole numbers.
	//
	//              If nearest power is zero, provide an error message.

	int usrInput = 0;

	cout << "Enter a number to round to the nearest power of 2.";
	cin >> usrInput;

	int roundedNum = usrInput / 2;

	for (int i = 1; i < 100000000000; i *= 2)
	{
		int check = i * 2;

		if (usrInput == i)
		{
			cout << "Your number " << usrInput << " is a power of 2!\n";
			break;
		}
		else
		{
			if (i < usrInput && check > usrInput)
			{
				int diff = usrInput - i;
				usrInput -= diff;
				cout << "Your number rounded to the nearest power of 2: " << usrInput << endl;
				break;
			}
		}
	}

	// 4.) FOUR FUNCTION DISPOSABLE CALCULATOR

	int usrIn = 0;
	int usrIn2 = 0;
	int usrIn3 = 0;
	int add = 0;
	int sub = 0;
	int mult = 0;
	int div = 0;

	cout << "Enter a choice:\n" << "1.) Addition\n" << "2.) Subtraction\n" << "3.) Multiplication\n" << "4.) Division";
	cin >> usrIn;

	switch (usrIn)
	{
	case 1:
		cout << "Enter a whole number: ";
		cin >> usrIn2;
		cout << "Enter a number to add to the previous number: ";
		cin >> usrIn3;
		add = usrIn2 + usrIn3;
		cout << "Your numbers added are: " << add << endl;
		break;
	case 2:
		cout << "Enter a whole number: ";
		cin >> usrIn2;
		cout << "Enter a number to subtract from the previous number: ";
		cin >> usrIn3;
		sub = usrIn2 - usrIn3;
		cout << "Your numbers subtracted are: " << sub << endl;
		break;
	case 3:
		cout << "Enter a whole number: ";
		cin >> usrIn2;
		cout << "Enter a number to multiply by the previous number: ";
		cin >> usrIn3;
		mult = usrIn2 * usrIn3;
		cout << "The product of your numbers is: " << mult << endl;
		break;
	case 4:
		cout << "Enter a whole number: ";
		cin >> usrIn2;
		cout << "Enter a number to divide by the previous number (Remember if you enter 0 it's not a legal operation): ";
		cin >> usrIn3;
		if (usrIn3 != 0)
		{
			div = usrIn2 / usrIn3;
			cout << "Your numbers divided are: " << div << endl;
		}
		else
			cout << "It's an illegal operation to divide by 0!\n";
		break;
	default:
		cout << "You didn't enter valid numbers!\n";
		break;
	}

	// Skip a line
	cout << "\n";

	// 5.) A BATTLE OF PREHISTORIC PROPORTIONS

	int playerStrength = 0;
	int dinoStrength = 4;
	int playerRPSChoice = 0;
	int dinoRPSChoice = 2;
	int playerBattlesFought = 0;
	int dinoBattlesFought = 2;
	int playerVitC = 0;
	int playerPoints = 0;
	int dinoPoints = 0;
	char playerSleep = 'n';
	char playerFear = 'y';
	char playerRun = 'n';
	char yesLowerAnswer = 'y';
	char yesUpperAnswer = 'Y';
	char noLowerAnswer = 'n';
	char noUpperAnswer = 'N';

	cout << "OMG! THERE'S A DINOSAUR OVER THERE, YOU HAVE TO GO FIGHT IT!\n";
	cout << "How would you rate your strength on a scale of 1 - 10? ";
	cin >> playerStrength;

	if (playerStrength > dinoStrength)
	{
		playerPoints++;
		cout << "Awesome you're stronger than the dino!\n" << "You get a point!\n" << "Player: " << playerPoints << endl;
	}
	else
	{
		dinoPoints++;
		cout << "Wow! The Dino is stronger than you!\n" << "Dino: " << dinoPoints << endl;
	}

	cout << "Which of the following are you going to take into battle: \n" << "1.) A Sack Of Potatoes (Rock)\n" << "2.) An Invisibility Cape (Paper)\n"
		<< "3.) The Mango Blade (Scissors): ";
	cin >> playerRPSChoice;

	switch (playerRPSChoice)
	{
	case 1:
		dinoPoints++;
		cout << "Oh No! The Dino used it's invisibility cape to disappear and give you a few good hits!\n" << "Dino: " << dinoPoints << endl;
		break;
	case 2:
		cout << "You both chose the invisibility cloak, so you're just hiding from each other!\n";
		break;
	case 3:
		playerPoints++;
		cout << "Great! You smacked that Dino with your Mango Blade, it broke and juiced everywhere!\n" << playerPoints << endl;
		break;
	default:
		cout << "You didn't make a choice? Why? Ok, moving on...\n";
	}

	cout << "How many battles have you fought in the past: ";
	cin >> playerBattlesFought;

	if (playerBattlesFought > dinoBattlesFought)
	{
		playerPoints++;
		cout << "Awesome! You have more experience than the Dino!\n" << "Player: " << playerPoints << endl;
	}
	else
	{
		dinoPoints++;
		cout << "Oh, that's too bad, the Dino has more experience under it's belt!\n" << "Dino: " << dinoPoints << endl;
	}

	cout << "Did you get enough sleep (y or n): ";
	cin >> playerSleep;

	if (playerSleep == yesLowerAnswer || playerSleep == yesUpperAnswer)
	{
		playerPoints++;
		dinoPoints++;
		cout << "Both you and the dino got enough sleep!\n" << "Player: " << playerPoints << endl << "Dino: " << dinoPoints << endl;
	}
	else
	{
		dinoPoints++;
		cout << "That's too bad! The Dino did!\n" << "Dino: " << dinoPoints << endl;
	}

	cout << "How much Vitamin C do you get everyday (mg): ";
	cin >> playerVitC;

	if (playerVitC >= 75)
	{
		playerPoints++;
		cout << "That's great! You're getting your required Vitamin C!\n" << "Player: " << playerPoints << endl;
	}
	else
		cout << "That's too bad! You should get more!\n";

	cout << "Are you scared? (y or n): ";
	cin >> playerFear;
	
	if (playerFear == 'y' || playerFear == 'Y')
	{
		playerPoints++;
		cout << "It's ok to be scared! It's good to acknowledge it, too!\n" << "Player: " << playerPoints << endl;
	}
	else
	{
		playerPoints--;
		cout << "Liar! It's a effing Dinosaur!\n" << "Player: " << playerPoints << endl;
	}

	cout << "Are you going to run(y or n) : ";
	cin >> playerRun;

	if (playerRun == 'y' || playerRun == 'Y')
	{
		playerPoints--;
		cout << "You tripped over a rock trying to run, and sprang your ankle!\n" << "Good job dumbass!\n" << "Player: " << playerPoints << endl;
	}
	else if(playerRun == 'n' || playerRun == 'N')
	{
		playerPoints++;
		cout << "Wow! You're brave! I'd crap my pants!\n" << "Player: " << playerPoints << endl;
	}

	if (playerPoints > dinoPoints)
		cout << "You defeated a freakin' DINOSAUR! You're a BADASS!\n";
	else if (playerPoints < dinoPoints)
		cout << "You got killed by a dinosaur! I'd say that's pretty badass, because you fought it! You still died though, so you lose!\n";
	else
		cout << "You and the dinosaur just tired each other out! This is super boring to watch; I'm leaving!\n";

	cout << "Player: " << playerPoints << "          " << "Dino: " << dinoPoints << endl;


	/** TODO CHALLENGE QUESTIONS **/








	/** Activity Walkthrough **/
	/* int arbNum = 4; // 2.) Create an integer w/ an arbitrary value.
	bool arbNumChanged = false;

	int userInput = 0;
	int userLoops = 0;
	bool userFinished = false;
	
	// Using do while loop to show the value changed and use all branches of if, else, else if statement
	do
	{
		if (arbNum > 3 && arbNum < 7)  // 3a.) Print a message to the console if the integer exceeds a certain value using an if statement.
		{
			cout << arbNum << " is greater than 3 and less than 7!\n";
			arbNum = 2;
		}
		else if(arbNum < 3 && arbNum > 0) // 3b.) Changed the value of arbNum to show execution of else statement.
		{
			cout << arbNum << " is less than 3 and greater than 0!\n";
			arbNum = 3;
		}
		else if(arbNum == 3) // 3c. & 3d.) Changed the value of arbNum to be the same as 3 to uses this branch.
		{
			cout << arbNum << " is the same as 3!\n";
			arbNum = 8;
		}
		else // 3e. & 3f.) Changed value doesn't meet any of the other criteria, so it uses this branch.
		{
			cout << arbNum << " does not meet any of the other criteria!\n";
			arbNumChanged = !arbNumChanged;
		}

		cout << "\n";

	} while (!arbNumChanged);

	// Do while loop to take in user input mulitple times and use all branches of if, else if, else statement.
	do
	{
		// Print Out Choices
		cout << "Please Enter A Choice:\n" << "1) Sometimes You Feel Like A Nut!\n"
			<< "2) You're Left and You're Right...\n" << "3) A Bird In The Hand Is Better Than... ";
		
		// Take In User Input
		cin >> userInput;

		// Branches The Choices Map To
		if (userInput == 1)
		{
			cout << "Sometimes You Dont!\n";
			userLoops += 1;
		}
		else if (userInput == 2)
		{
			cout << "You're Up And You're Down...\n";
			userLoops += 1;
		}
		else if (userInput == 3)
		{
			cout << "Two In The Bush!\n";
			userLoops += 1;
		}
		else
			cout << "You didn't choose a valid choice!\n";

		if (userLoops == 3)
			userFinished = !userFinished;
		
		// Skip A Line
		cout << "\n";

	} while (!userFinished); */

	// Pauses system and waits for user input
	system("pause");

	// Ends program
	return 0;
}