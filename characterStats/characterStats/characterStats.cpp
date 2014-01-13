//
//  characterStats.cpp
//  characterStats
//
//  Created by Josh Kennedy on 10/5/13.
//  Copyright (c) 2013 Josh Kennedy. All rights reserved.
//

// Program reads text from a text file named "characterStats.txt"
// and writes out the number of characters in the file, along with the
// number of letters and the number of non-whitespace characters.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
    // Declare input stream
    string fileToOpen = "/Users/joshuakennedy/Documents/Projects/CS 200/characterStats/characterStats/characterStats.txt";
    ifstream fin;
    char val = 'x';
    int count = 0;
    int nws = 0;
    int letters = 0;
	
	// Open the file
    fin.open(fileToOpen);
    
	// Check for successful file open
    if (fin.fail())
    {
        cerr << "Couldn't open " << fileToOpen << ". Please ensure it exists and you have read/write access!" << endl;
        exit(-1);
    }
	
	// Pre-processing buffer, since we need a value to test the while condition.
	val = fin.get();
    
	// Loop to read from file
	// Count the number of characters along with
	//   the number of letters and non-whitespace characters
    while (val != EOF)
    {
        // Increment character count.
        count++;
        
		// Checks if character value is a whitespace character.
		if (!isspace(val))
			nws++;
        
        // Checks if character value is within the boundaries of the lowercase or uppercase alphabet.
        if (isalpha(val))
            letters++;
		
		val = fin.get();
	}
    
    
	// Close the file
    fin.close();
    
    cout << "The file contains:\n";
    cout << "    " << count << " characters\n";
    cout << "    " << nws << " non-whitespace characters\n";
    cout << "    " << letters << " letters\n";
    
	return 0; // successful completion
}

/* Test with characterStats.txt
 
 The file contains:
 65 characters
 52 non-whitespace characters
 45 letters
 Program ended with exit code: 0

*/
