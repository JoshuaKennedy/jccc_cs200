//
//  testScoreMain.cpp
//
//  Created by Josh Kennedy on 11/26/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>

#include "testScore.h"

using namespace std;

int main(int argc, const char * argv[])
{
    TestScore test = TestScore();
    int score = 0;
    
    cout << "Enter test score: ";
    cin >> score;
    
    do
    {
        test.recordScore(score);
        
        cout << "Best score is " << test.reportBestScore() << '.' << endl;
        if (score == test.reportBestScore())
        {
            cout << "You have a new best score!!" << endl;
        }
        
        cout << endl << "Enter test score (less than 0 to quit): ";
        cin >> score;
    } while (score > 0);
    
    return 0;
}

/* output:
 
 Enter test score: 75
 Best score is 75.
 You have a new best score!!
 
 Enter test score (less than 0 to quit): 50
 Best score is 75.
 
 Enter test score (less than 0 to quit): 86
 Best score is 86.
 You have a new best score!!
 
 Enter test score (less than 0 to quit): -1
 Program ended with exit code: 0
 
 */

