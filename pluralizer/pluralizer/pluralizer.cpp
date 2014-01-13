//
//  pluralizer.cpp
//
//  Created by Josh Kennedy on 10/19/13.
//  Copyright (c) 2013 Joshua Kennedy. All rights reserved.
//

#include <iostream>

using namespace std;

void makePlural(const char*, char*);

int main(int argc, const char * argv[])
{
    char text[15];
    char plural[15];
    
    cout << "Enter string (14 char max): ";
    cin >> text;
    
    makePlural(text, plural);
    
    cout << "string as plural: " << plural << endl;
    
    return 0;
}

void makePlural(const char* original, char* plural)
{
    int index = 0;
    int length = 0;
    
    while(original[index] != '\0')
    {
        plural[index] = original[index];
        
        length++;
        
        index++;
    }
    
    plural[length] = 's';
    plural[length + 1] = '\0';
}

/* Test:
 
 Enter string (14 char max): taco
 string as plural: tacos
 Program ended with exit code: 0
 
*/

