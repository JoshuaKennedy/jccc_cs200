// inClass02.cpp - In class excercise #2 for CS200
// Created by Josh Kennedy on 21 August 2013

// CS 200  IN CLASS EXERCISE 02

//   Write, compile, build and execute a C++ program
//      to input 3 integers and print how many of
//      3 integers are even
//      RECALL:  an integer is even if the remainder when dividing by 2 gives 0

//   ALGORITHM:
//      -  initialize a counter to 0
//      -  prompt the user to enter 3 integers
//      -  read the 3 integers
//      -  if the 1st integer is even, add 1 to the counter
//      -  if the 2nd integer is even, add 1 to the counter
//      -  if the 3rd integer is even, add 1 to the counter
//      -  print the value of the counter with an appropriate description


#include <iostream>
#include <string>
#include <sstream>

// Quick function to save on lines of code.
std::string isEven(int number)
{
	// Perform modulus division to see if the number is even.
	bool expression = (number % 2 == 0);

	// Do a ternary operation to save on lines of code.
	std::string endText = (expression ? " is even." : " is odd.");

	// You can't concatenate an int and a std::string so we create a string stream and place the int, and the endText in there.
	std::stringstream ss;
	ss << number << endText;

	// Return the string from the string stream.
	return ss.str();
}

// Entry point to application.
int main (int argc, char* argv[])
{
	// Declare and initialize variables.
	int counter = 0, num1 = 0, num2 = 0, num3 = 0;

	// Prompt user for input.
	std::cout << "Please enter 3 integers: ";

	// Grab input from user.
	std::cin >> num1 >> num2 >> num3;

	// Perform the modulus and display it to the user.
	std::cout << isEven(num1) << "\n" << isEven(num2) << "\n" << isEven(num3) << std::endl;

	return 0;
}

/* Output:

Test #1
---

Test #2
---

Test #3
---

*/
