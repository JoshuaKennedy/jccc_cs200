//
//  main.cpp
//  inClass16
//
//  Created by Josh Kennedy on 11/6/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//
//  Program determines whether a word or phrase is a palindrome.

#include <iostream>
using namespace std;

bool isPalindrome(const char *);

int main()
{
	char x[100];
	cout << "Enter a word or phrase: ";
	cin.getline(x,100);
	
	if(isPalindrome(x))
		cout << "This is a palindrome.\n";
	else
		cout << "This is NOT a palindrome.\n";
    
	return 0;
}

bool isPalindrome(const char * xPtr)
{
	const char * endPtr = xPtr;
    
	// loop to move endPtr to the NULL character in the string
    while (*endPtr != NULL)
    {
        endPtr++;
    }
    
	// move endPtr to the character before the NULL
	endPtr--;
    
	// loop to check for not a palindrome
	// each time in the loop, increment xPtr and decrement endPtr
    while (xPtr < endPtr)
    {
        if (*xPtr != *endPtr)
            return false;
        
        xPtr++;
        endPtr--;
    }
    
    return true;
}

/* output
 
 Enter a word or phrase: tacocat
 This is a palindrome.
 Program ended with exit code: 0
 
 */

