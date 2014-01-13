//
//  testScore.cpp
//
//  Created by Josh Kennedy on 11/26/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include "testScore.h"

// Constructor Implementation
TestScore::TestScore()
{
    this->bestScore = 0;
}

// Member Function Implementations
void TestScore::recordScore(int score)
{
    if (score > this->bestScore)
    {
        this->bestScore = score;
    }
}

int TestScore::reportBestScore()
{
    return this->bestScore;
}