/*
 * numberCompare.cpp - Does math and comparisons and stuff.
 * Created by Josh Kennedy on 21 August 2013
 */

#include <iostream>

int main (int argc, char* argv[])
{
	// Variable declarations
	int numbers[3];
	int smallest = 0, largest = 0, sum = 0, product = 0;
	double average = 0.0;
	int position = 0;

	// Prompt user for input and get input

	while (position < 3)
	{
		int temp;
		std::cout << "Enter one integer: ";
		std::cin >> temp;
		numbers[position] = temp;

		position++;
	}

	largest = numbers[0];
	smallest = numbers[0];

	// Figure out the largest and smallest numbers
	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] > largest)
			largest = numbers[i];
		if (numbers[i] < smallest)
			smallest = numbers[i];
	}

	// Perform mathe-magic. :-)
	sum += numbers[0];
	sum += numbers[1];
	sum += numbers[2];

	average = (double)sum / 3.0; // We have to cast sum as a double or else we get no precision.

	product = numbers[0] * numbers[1] * numbers[2];

	// Print out everything
	std::cout << "Sum: " << sum << "\nAverage: " << average << "\nProduct: " << product << "\nLargest number: " << largest << "\nSmallest number: " << smallest << std::endl;

	return 0;
}

/* Test Cases:

Enter one integer: 34
Enter one integer: 45
Enter one integer: 38
Sum: 117
Average: 39
Product: 58140
Largest number: 45
Smallest number: 34
Press any key to continue . . .

Enter one integer: 44
Enter one integer: 22
Enter one integer: 15
Sum: 81
Average: 27
Product: 14520
Largest number: 44
Smallest number: 15
Press any key to continue . . .

Enter one integer: 10
Enter one integer: 10
Enter one integer: 10
Sum: 30
Average: 10
Product: 1000
Largest number: 10
Smallest number: 10
Press any key to continue . . .

*/
