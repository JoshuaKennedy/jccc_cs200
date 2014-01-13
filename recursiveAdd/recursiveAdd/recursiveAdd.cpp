//
//  recursiveAdd.cpp
//
//  Created by Josh Kennedy on 11/6/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.

#include <iostream>

using namespace std;

// Function prototype
int sum(int);

int main(int argc, const char * argv[])
{
    for (int i = 3; i <= 30; i += 3)
    {
        cout << i << '\t' << sum(i) << endl;
    }
    
    return 0;
}

int sum(int num)
{
    if (num <= 1)
        return 1;
    else
        return sum(num - 1) + num;
}

