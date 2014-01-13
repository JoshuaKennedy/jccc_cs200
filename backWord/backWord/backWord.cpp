/**
 * @author Josh Kennedy
 * @file backWord.cpp 
 * @date 19 October 2013
 */

#include <iostream>
#include <iomanip>
using namespace std;

void reverse(char word[]);     // function prototype

int main(int argc, char* argv[])
{
	const int MAX_SIZE = 15; // Max word size of word, allow for '\0'
	char word[MAX_SIZE];
    
	cout << endl << "Enter a word : ";
	cin >> setw(MAX_SIZE) >> word;
	cout << "You entered the word " << word << endl;
    
	reverse(word);
    
	cout << "The word in reverse order is " << word << endl;
}

void reverse(char word[])
{
	// you can have local scalar variables of type int and char
	// However, you cannot have any local array variables
	// This function will reverse the characters in the array word
	// An Algorithm for this problem will be presented in class
    
    int index = 0;
    int length = 0;
    
    char temp = '\0';
    
    // get length of char array
    while (word[index] != '\0')
    {
        length++;
        index++;
    }
    
    int backward = length - 1;
    
    // we're going front -> back AND back -> front simutaneously!
    for (index = 0; index < backward; index++, backward--)
    {
        // Store a character temporarily.
        temp = word[index];
        
        // put next backward char in front
        word[index] = word[backward];
        
        // put the next forward char to the back
        word[backward] = temp;
    }
}
