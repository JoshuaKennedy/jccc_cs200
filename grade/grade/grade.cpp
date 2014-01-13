//  grade.cpp
//
//  Created by Josh Kennedy on 10/11/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.

#include <iostream>

using namespace std;

// Function prototype.
int grade(const char[], const char[], int);

int main(int argc, const char* argv[])
{
    // Variable declarations.
	char key[11] = "AABDEFABCD";
	char myTest[11] = "BABEEFAADD";
    
    // Rather than hard coding array length, just divide sizeof key by the sizeof first array element.
	cout << "I got " << grade(key, myTest, (sizeof(key) / sizeof(key[0]))) << " questions correct" << endl;
    
    // return sucess
    return 0;
}

int grade(const char master[], const char student[], int count)
{
    // variable declaration.
    int score = 0;
    
    // iterate through array
    for (int c = 0; c < count - 1; c++)
    {
        // compare master to student, if same then increment score.
        if (master[c] == student[c])
            score++;
    }
    
    // return score.
    return score;
}
