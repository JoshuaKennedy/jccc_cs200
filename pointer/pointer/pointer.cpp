//
//  pointer.cpp
//
//  Created by Josh Kennedy on 11/6/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int largeArray(const int[], int);
int largePointer(const int* , int);

void fillArray(int* , int howMany);

void printArray(const char*, ostream&, const int*, int howMany);

//  VALUES FOR LOW AND HIGH OF RANDOM DATA
const int low = 50;
const int high = 90;

int main()
{
	const int MAX_SIZE = 40;
	int info[MAX_SIZE];
    
    // Get user input and check it.
	int used;
	cout << "How many elements in the array (between 1 and 40)? ";
	cin >> used;
    
	while ( used <= 0 || used > MAX_SIZE )
	{
		cout << "Enter a value between 1 and " << MAX_SIZE << endl;
		cout << "How many elements in the array? ";
		cin >> used;
	}
    
	fillArray(info,used);
	printArray("Array of data",cout,info,used);
    
	cout << "The largest element using subscripts is " << largeArray(info,used) << endl;
    
	cout << "The largest element using pointers is " << largePointer(info,used) << endl;
    
    return 0;
} // end main ***************************

void printArray(const char* m, ostream& out, const int* p, int hm)
{
    // Print the string.
	out << m << endl;
    
    // Print the string putting each character on a separate line.
	for(int i = 0; i < hm; i++)
	{
		out << p[i] << endl;
	}
}

void fillArray(int* p, int howMany)  // as parmeters pointers and arrays are the same
{
    // Set the range for the random number generator.
	int range = high - low + 1;
    
    // Initialize the seeder with the time.
	srand(static_cast<unsigned int>(time(NULL)));
    
    // Fill the array with random numbers.
	for( int i = 0; i < howMany; i++)
	{
		p[i] =  rand() % range + low;
	}
}

int largeArray(const int data[], int howMany)   // use subscripts
{
	int largest = data[0];  // set largest to first element of array
    
	//   ******   STUDENT WILL WRITE THE CODE TO FIND THE LARGEST NUMBER
	//   ******        USE SUBSCRIPTS TO ACCESS THE ELEMENTS
    
    for (int i = 1; i <= howMany; i++)
    {
        if (data[i] > largest)
            largest = data[i];
    }
	
	return largest;
}

int largePointer(const int* data, int howMany)   // use pointers
{
	int largest = *data;  // set largest to first element of array
    
	//   ******   STUDENT WILL WRITE THE CODE TO FIND THE LARGEST NUMBER
	//   ******        USE POINTERS TO ACCESS THE ELEMENTS
    
    while (*data != NULL)
    {
        if (*data > largest)
            largest = *data;
        
        data++;
    }
	
	return largest;
}

/* OUTPUT:
 
 How many elements in the array (between 1 and 40)? 5
 Array of data
 68
 78
 53
 67
 61
 The largest element using subscripts is 78
 The largest element using pointers is 78
 Program ended with exit code: 0
 
 */

