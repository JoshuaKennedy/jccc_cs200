//
//  dynamic.cpp
//
//  Created by Josh Kennedy on 11/6/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArray(const char*, ostream&, const int*, int howMany);

int main()
{
	int* info;
    
	int used;
    
    // Get the data from user and check it.
	cout << "How many elements in the array? ";
	cin >> used;
    
	while ( used <= 0 )
	{
		cout << "Enter a value of 1 or more" << endl;
		cin >> used;
	}
    
	//  STUDENT WRITE THE CODE TO ACQUIRE THE MEMORY FOR THE ARRAY FROM THE HEAP
    info = new int[used];
    
	//  STUDENT USING SUBSCRIPTS WRITE THE CODE TO FILL THE ARRAY
	//        WITH MULTIPLES OF 3 -  cell 0 holds 0, cell 1 holds 3,
	//                               cell 2 holds 6, etc.
    
    for (int i = 0; i < used; i++)
    {
        info[i] = i * 3;
    }
    
	//   call printArray to check your work
	printArray("Array of data", cout, info, used);
    
	//   STUDENT WRITE THE CODE TO RETURN THE MEMORY TO THE HEAP
    delete []info;
    
    return 0;
} // end main ***************************

void printArray(const char* m, ostream& out, const int* p, int hm)
{
	out << m << endl;
    
	for(int i = 0; i < hm; i++)
	{
		out << p[i] << endl;
	}
}

/* OUTPUT:
 
 How many elements in the array? 5
 Array of data
 0
 3
 6
 9
 12
 Program ended with exit code: 0
 
 */

