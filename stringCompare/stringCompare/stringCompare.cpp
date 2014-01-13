/**
 * @author Josh Kennedy
 * @file stringCompare.cpp
 * @date 19 October 2013
 */

#include <iostream>
#include <iomanip>
using namespace std;

/* Write a function prototype for stringCompare1 */
int stringCompare1(char* str1, char* str2);

int main()
{
	char string1[ 100 ], string2[ 100 ];
    
	cout << "Enter two strings: ";
	cin >> setw(100) >> string1 >> string2;
    
	cout << "The value returned from stringCompare1(\"" << string1
    << "\", \"" << string2 << "\") is "
    << stringCompare1(string1, string2)
    << '\n';
    
	return 0;
} // end main

/* Write a function header for stringCompare1 */
int stringCompare1(char* str1, char* str2)
{
	int index = 0;
	
	// array subscript notation
	/* Write a loop that iterates through both strings
     using array subscript notation, until index contains the
     first index where the strings do not match or the index
     of the null character */
    
    while (str1[index] == str2[index])
    {
        if (str1[index] == '\0' && str2[index] == '\0')
            return 0;
        
        index++;
    }
    
	/* Write code to return -1 or 1 based on which
     of s1[ index ] and s2[ index ] is greater
     -1 if string1 is less than string2
     1 if string1 is greater than string2 */
    
    if (str1[index] < str2[index])
        return -1;
    else if (str1[index] > str2[index])
        return 1;
    
    // otherwise an error occurred.
    return -2;
    
} // end function stringCompare1

/* Tests:
 
 Enter two strings: meow cat
 The value returned from stringCompare1("meow", "cat") is 1
 Program ended with exit code: 0
 
 Enter two strings: heavy metal
 The value returned from stringCompare1("heavy", "metal") is -1
 Program ended with exit code: 0
 
*/
