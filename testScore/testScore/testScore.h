//
//  testScore.h
//
//  Created by Josh Kennedy on 11/26/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#ifndef TEST_SCORE_H_
#define TEST_SCORE_H_

#include <iostream>

class TestScore
{
public:
    TestScore();
    void recordScore(int);
    int reportBestScore();
private:
    int bestScore;
};

#endif
