/*
* @author Your First and Last Name
* @file multiples.cpp */

#include <iostream> // allows program to perform input and output
using namespace std;

int main()
{
	/* Write variables declarations here */
	//  ENTER THE CODE BELOW
	int number1 = 0, number2 = 0;

	cout << "Enter two integers: "; // prompt

	/* Write a cin statement to read data into variables here */
	//  ENTER THE CODE BELOW
	cin >> number1 >> number2;

	// using modulus operator
	//  WRITE THE CODE INSIDE THE  (              )
	//   RECALL:    30 % 5 gives an answer of 0, so 30 is a multiple of 5
	//              32 % 5 gives an answer of 2, (not 0) so 32 is NOT a multiple of 5
	/* Write a condition that tests whether number1 is a multiple of
		   number2 */
	if ((number2 % number1) == 0)	//  ENTER THE CODE INSIDE THE (     )
		cout << number1 << " is a multiple of " << number2 << endl;


	/* Write a condition that tests whether number1 is not a multiple
		   of number2 */
	if ((number2 % number1) != 0)	//  ENTER THE CODE INSIDE THE (       )
		cout << number1 << " is not a multiple of " << number2 << endl;

	return 0; // indicate successful termination

} // end main

/* Test Cases:

Test #1
---
Enter two integers: 45 15
45 is not a multiple of 15
Press any key to continue . . .

Test #2
---
Enter two integers: 12 36
12 is a multiple of 36
Press any key to continue . . .

Test #3
---
Enter two integers: 10 10
10 is a multiple of 10
Press any key to continue . . .

Test #4
---
Enter two integers: 12 5
12 is not a multiple of 5
Press any key to continue . . .

*/