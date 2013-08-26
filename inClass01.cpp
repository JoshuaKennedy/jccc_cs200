// CS 200  IN CLASS EXERCISE 01    
// examples of operators and library predefined functions

#include <iostream>

using namespace std;

//   NAME: Josh Kennedy

int main()
{
	// Declare 3 integer variables - length, width and area
	int length, width, area = 0;

	// Prompt the user to enter length and width
	cout << "Please enter length and width integers: ";
	cin >> length >> width;

	// Calculate the area - length times width
	area = length * width;

	// Display the length, width and area with descriptions
	cout << "Length entered is... " << length << "\n" << "Width entered is... " << width << "\n" << "Area calculated is... " << area << endl;

	return 0;
}

/*
 Please enter length and width integers: 50 10
Length entered is... 50
Width entered is... 10
Area calculated is... 500
Press any key to continue . . .
*/
