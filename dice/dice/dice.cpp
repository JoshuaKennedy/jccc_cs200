//  dice.cpp
//  Created by Josh Kennedy on 10/12/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main(int argc, const char * argv[])
{
    const long ROLLS = 36000;
	const int SIZE = 13;
    
	// array expected contains counts for the expected
	// number of times each sum occurs in 36 rolls of the dice
    
	/* Write the declaration of array expected here. Assign an
     initializer list containing the expected values here. Use
     SIZE for the number of elements */
    int expected[SIZE] = { /* something */ };
    
	int x; // first die
	int y; // second die
    
	/* Write declaration for array sum here. Initialize all
     elements to zero. Use SIZE for the number of elements */
    int sum[SIZE];
    
    for (int s = 0; s < SIZE; s++)
    {
        sum[s] = 0;
    }
    
	srand(static_cast<unsigned int>(time(0)));
    
	// roll dice 36,000 times
	/* Write a for loop that iterates ROLLS times. Randomly
     generate values for x (i.e., die1) and y (i,e, die2)
     and increment the appropriate counter in array sum that
     corresponds to the sum of x and y */
    for (int r = 0; r < ROLLS; r++)
    {
        x = rand() % 7 - 1;
        y = rand() % 7 - 1;
        
        sum[0] = x + y;
    }
    
	cout << setw(10) << "Sum" << setw(10) << "Total" << setw(10) << "Expected" << setw(10) << "Actual\n" << fixed << showpoint;
    
	// display results of rolling dice
	for (int j = 2; j < SIZE; j++)
    {
		cout << setw(10) << j << setw(10) << sum[j]
        << setprecision(3) << setw(9)
        << 100.0 * expected[j] / 36 << "%" << setprecision( 3 )
        << setw(9) << 100.0 * sum[ j ] / ROLLS << "%\n";
    }
    
	return 0; // indicates successful completion
}

