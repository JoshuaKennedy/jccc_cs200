//
//  frequency.cpp
//
//  Created by Josh Kennedy on 10/12/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//
//  The program generates 500 numbers between 1 and 6 and stores them in an array
//  The program loops and counts how many times each number occurs.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateData(int [], int count);

int countValue(const int [], int howMany, int value);

int main()
{
	int data[500];
    int dataCount = (sizeof(data) / sizeof(data[0]));
	
    // call the function to generate 500 numbers
    // between 1 and 6, and store the values in the data array
    generateData(data, dataCount);
	
	for ( int i = 1 ; i <= 6 ; i++ )
	{
		cout << i << " " << countValue(data, dataCount, i) << endl;
	}
    
    return 0;
}

void generateData(int d[], int cnt)
{
    // For less predictable results use, srand(time(NULL));
    srand(12345);
	int dice;
	for(int i = 0; i < cnt ; i++)
	{
		dice = rand() % 6 + 1; // generate a random number between 1 and 6
		d[i] = dice;
	}
}

int countValue(const int d[], int howMany, int value)
{
	int total = 0;
    
	for( int i = 0; i < howMany ; i++)
	{
        // adjust the total if number in cell i is equal to the parameter value
        if (d[i] == value)
            total++;
    }
    
	return total;
}

/* Output:
 1 85
 2 75
 3 75
 4 83
 5 77
 6 105
 Program ended with exit code: 0
*/
