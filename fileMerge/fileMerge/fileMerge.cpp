//
//  fileMerge.cpp
//
//  Created by Josh Kennedy on 10/10/13.
//
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//
//  This program merges 2 input files (each already sorted in ascending order)
//  into 1 output file sorted in ascending order.  The numbers in the 2 files
//  are decimal numbers.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void fileFail(string file, int exitCode);

int main(int argc, const char * argv[])
{
    // declare variables
    double num1 = 0, num2 = 0;
    const string file1 = "/Users/joshuakennedy/Documents/Projects/CS 200/fileMerge/fileMerge04.txt";
    const string file2 = "/Users/joshuakennedy/Documents/Projects/CS 200/fileMerge/fileMerge05.txt";
    const string file3 = "/Users/joshuakennedy/Desktop/fileMerge06.txt";
    ifstream input1;
    ifstream input2;
    ofstream output;
    
	// open 2 input files and 1 output file and check for successful open
    input1.open(file1);
    
    if (input1.fail())
        fileFail(file1, 1);
    
    input2.open(file2);
    
    if (input2.fail())
        fileFail(file2, 2);
    
    output.open(file3);
    
    if (output.fail())
        fileFail(file3, 3);
    
	// read a number from the 1st file
    input1 >> num1;
    
	// read a number from the 2nd file
	input2 >> num2;
    
	//loop while not eof on the 1st file and not eof on the 2nd file
    while (!input1.eof() && !input2.eof())
    {
        // if the 1st number is less than the 2nd number
        // write the 1st number to the output file
        // read another number from the 1st file
        // else
        // write the 2nd number to the output file
        // read another number from the 2nd file
        if (num1 < num2)
        {
            output << num1;
            input1 >> num1;
        }
        else
        {
            output << num2;
            input2 >> num2;
        }
        
        output << '\n';
    }
	// end of loop
    
	// if end-of-file was found on the 1st file
    // write all remaining numbers from the 2nd file
    if (input1.eof())
    {
        while (!input2.eof())
        {
            output << num2;
            input2 >> num2;
            
            output << '\n';
        }
    }
    
    input1.close();
    input2.close();
    output.close();
    
    return 0;
}

void fileFail(string file, int exitCode)
{
    cout << "Couldn't open " << file << ". Please ensure you have read/write permissions." << endl;
    exit(exitCode);
}

/* Output:

fileMerge03.txt

 123.45
 223.73
 323.78
 415.87
 563.12
 623.4
 734.12
 825.33
 912.53
 985.29
 993.73
 
fileMerge06.txt
 
 134.63
 269.23
 329.28
 423.65
 525.3
 632.94
 725.85
 856.89
 
*/
