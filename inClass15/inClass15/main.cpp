//
//  inClass15.cpp
//
//  Created by Josh Kennedy on 4 November 2013
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//
//  Program counts the number of vowels in a string of letters read in (revised to use pointers)

#include <iostream>
#include <iomanip>
using namespace std;

int countVowels(const char *);

int main()
{
	char x[100];
	// get input
	cout << "Enter a string with no blanks ";
	cin >> setw(100) >> x;  // setw(100) limits input to 100 chars
    
	// display the string and how many vowels
	cout << x << endl;
	cout << "The number of vowels is " << countVowels(x) << endl;
    
	return 0;
}

int countVowels(const char * xPtr)
{
	// count the vowels whether they be upper or lower case
    
    int count = 0;
    
    while (*xPtr != NULL)
    {
        char letter = tolower(*xPtr);
        
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            count++;
        
        xPtr++;
    }
    
    return count;
}

/* output:
 
 Enter a string with no blanks josh
 josh
 The number of vowels is 1
 Program ended with exit code: 0
 
 */

