#include <iostream>
#include <cstring>

void doSomething(int x);

void AddStrings(char dst[],int size, char src1[], char src2[]);

struct Player
{
	char name[80];
};

/** Closed Activities **/

void Greeting();
void FavColor();
void WhiteSpace();
void PigLatin();

/** Open Activities **/
void PalindromeTest();

int main()
{
	/** CStrings **/

	// Definition
	char buffer[80];

	// Instatiation
	char cString[] = "Dinosaurs are cool!";
	char buffer2[80] = { 0 };

	// assignment
	strcpy_s(buffer, "String "); // Use strcpy_s in the <cstring> library

	// Determine how long the string is
	int length = strlen(buffer); // Is the actual number of characters not memory (sizeof gets the memory size)

	// String concatenation
	strcat_s(buffer, cString);
	strcat_s(buffer, 80, cString);

	// String Comparing
	int result = strcmp(buffer2, buffer);

	std::cout << buffer << std::endl;
	std::cout << buffer2 << std::endl;
	std::cout << result << std::endl;

	doSomething(result);
	char arr1[] = "Check Me Out! ";
	char arr2[] = { "No Way!" };
	char dest[80] = { 0 };

	AddStrings(dest, 80, arr1, arr2);

	/** Closed Activities **/

	/*Greeting();

	std::cout << "\n";

	FavColor();*/

	//WhiteSpace();

	//PalindromeTest();

	PigLatin();

	system("pause");
}

void doSomething(int x) // passed by reference
{
	x += 10;
}

void AddStrings(char dst[], int size, char src1[], char src2[])
{
	strcpy_s(dst, size, src1);
	strcat_s(dst, size, src2);
}

/** Closed Activities **/
void Greeting()
{
	char name[80];
	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << "Hello " << name << "!\n";
}

void FavColor()
{
	char color[80] = { 0 };
	char red[] = { 'r', 'e', 'd', 0 };
	char Red[] = { 'R','e', 'd', 0 };
	char Blue[] = {'B', 'l', 'u', 'e', 0 };
	char blue[] = { 'b', 'l', 'u', 'e', 0 };
	char orange[] = { 'o', 'r', 'a', 'n', 'g', 'e', 0 };
	char Orange[] = { 'O', 'r', 'a', 'n', 'g', 'e', 0 };

	std::cout << "Enter your favorite color: ";
	std::cin >> color;

	int check1 = strcmp(red, color);
	int check2 = strcmp(blue, color);
	int check3 = strcmp(orange, color);

	if ( check1 == 0)
		std::cout << "Red? Like the color of roses?\n";
	else if (check2 == 0)
		std::cout << "Blue like the sky!\n";
	else if (check3 == 0)
		std::cout << "Orange is also a fruit!\n";
	else
		std::cout << "I've never heard of that color before.\n";
}

void WhiteSpace()
{
	// UserInput character array
	char userInput[80];
	// Returns the results of the deleted whitespace
	char results[80];

	// Prompt the user to enter a string
	std::cout << "Enter a string: ";
	// Use cin.getline to get the user input
	std::cin.getline(userInput,80);

	// Get the length of the user's string
	int len = strlen(userInput);

	// Loops through each character to check if it's a space or not
	for (int i = 0; i < len; i++)
	{
		// ... if it's not a space (ascii 32) put the userInput element into the results element
		if (userInput[i] != 32)
			results[i] = userInput[i];
		// ... if it's a space (ascii 32) put the next element of userInput into the current results element
		else
			results[i] = userInput[i + 1];

		// Put a null terminator at the end of the results array
		results[i + 1] = 0;
	}

	 //Prints out the string without the whitespaces
	std::cout << "You string without whitespace: " << results << "\n";
}

/** Open Activities **/
void PalindromeTest()
{
	char userInput[80];
	char testing[80] = { 0 };
	char goodArray[80] = { 0 };

	std::cout << "Enter a word to test if it's a Palindrome: ";
	std::cin.getline(userInput, 80);

	strcpy_s(testing, 80, userInput);

	for (int i = strlen(userInput) - 1; i > -1; i--)
	{
		goodArray[i] = userInput[i];
	}

	for (int i = 0; i < strlen(userInput); i++)
	{
		userInput[i] = tolower(userInput[i]);
		goodArray[i] = tolower(goodArray[i]);

		if (userInput[i] == goodArray[i])
			testing[i] = userInput[i];
	}

	int check = strcmp(userInput, testing);

	if (check == 0)
		std::cout << "Your word is a palindrome!\n";
	else
		std::cout << "Your word isn't a palindrome!\n";
}

void PigLatin()
{
	char word[80] = { 0 };
	
	std::cout << "Enter a word for Pig Latin: ";
	std::cin.getline(word, 80);
	
	if (word[0] != 'a' || word[0] != 'e' || word[0] != 'i' || word[0] != 'o' || word[0] != 'u')
	{	
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] == 0)
			{
				word[i] = 'a';
				word[i++] = 0;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < strlen(word); i++)
		{
			word[i] = word[i++];

			if (word[i] == 0)
			{
				word[i] = 'w';
				word[i++] = 'a';
				word[i += 2] = 'y';
				break;
			}
		}
	}

	std::cout << word << std::endl;

}