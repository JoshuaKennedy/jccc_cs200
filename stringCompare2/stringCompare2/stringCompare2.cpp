//
//  stringCompare2.cpp
//
//  Created by Josh Kennedy on 11/6/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototype of stringCompare2 method
int stringCompare2(const char* str1, const char* str2);

int main(int argc, char* argv[])
{
    // Variable declarations.
	char string1[100];
    char string2[100];
    
    // Prompt and get input from user.
	cout << "Enter two strings: ";
	cin >> setw(100) >> string1 >> setw(100) >> string2;
    
    // Output the output from the algorithm.
	cout << "The value returned from stringCompare2(\"" << string1 << "\", \"" << string2 << "\") is " << stringCompare2(string1, string2) << '\n';
    
	return 0;
} // end main

/* Write a function header for stringCompare2 */
int stringCompare2(const char* str1, const char* str2)
{
	// pointer notation
	/* Write a loop that iterates through both strings
     using pointer notation, until both pointers point to
     the first character where the strings do not match
     or the index of the null character */
    
    // Iterate through both arrays and check if they're NULL or there's a mismatch.
    while ((*str1 != NULL && *str2 != NULL) && (*str1 == *str2))
    {
        // If both array positions are NULL, then they're matching.
        if (*str1 == '\0' && *str2 == '\0')
            return 0;
        
        // Increment the pointer position in both arrays.
        str1++;
        str2++;
    }
    
	/* Write code to return -1 or 1 based on which
     of *s1 and *s2 is greater:
     -1 if string1 less than string2
     1 if string1 greater than string2 */
    if (*str1 > *str2)
        return 1;
    else if (*str2 > *str1)
        return -1;
    
    // If there's an error.
    return -2;
} // end function stringCompare2

/* OUTPUT:
 
 Enter two strings: josh brandon
 The value returned from stringCompare2("josh", "brandon") is 1
 Program ended with exit code: 0
 
 */

