/**
 * @author Josh Kennedy
 * @file hangMan.cpp
 * @description "Hangman" word guessing game.
 * @date 20 October 2013
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void createTemplate(const char secretWord[], char guessTemplate[]);
void updateTemplate(const char secretWord[], char guessLetter, char guessTemplate[]);
bool matchTemplate(const char secretWord[], const char guessTemplate[]);

//--------------------------------------------------------------------
// Entry point of application.
//--------------------------------------------------------------------
int main(int argc, char* argv[])
{
	const int NUM_LINES = 25; // Number of lines on the screen
	const int MAX_SIZE = 15; // Max length of word.
    
	char secretWord[MAX_SIZE]; // Secret word to be guessed
    char guessTemplate[MAX_SIZE]; // Template showing correct guesses
	char guessLetter; // Letter guessed
    
	int numGuesses = 0; // Number of letters guessed
    int j = 0 ; // Counter
    
	// Get the secret word.
	cout << endl << "Enter the secret word: ";
	cin >> setw(MAX_SIZE) >> secretWord;
    
	// Scroll it off the screen.
	for (j = 0; j < NUM_LINES; j++)
		cout << endl;
    
	// Create an empty guess template.
	createTemplate(secretWord, guessTemplate);
    
	// Play the game.
	numGuesses = 0;
    
	while (!matchTemplate(secretWord, guessTemplate))
	{
		numGuesses++;
		cout << guessTemplate << endl;
        
		// Get a letter guess.
		cout << "Guess a letter: ";
		cin >> guessLetter;
        
		// Fill in the occurrences of this letter.
		updateTemplate(secretWord, guessLetter, guessTemplate);
	}
    
	// Display the secret word and the number of guesses.
	cout << guessTemplate << "=" << secretWord << endl;
	cout << "You guessed the word in " << numGuesses << " guesses" << endl;
    
	return 0;
}

void createTemplate (const char secretWord[], char guessTemplate[])
{
	//   The guessTemplate will be an array of characters, all cells
	//          filled with the char '-' and with a '\0' at the end
	//   The number of cells filled will be determined by the numbers
	//          of characters in secretWord
	//   If secretWord is the C++ string  monday
	//      Then guessTemplate will be    ------
    
	//   ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
    
    int i = 0;
    
    while (secretWord[i] != '\0')
    {
        guessTemplate[i] = '-';
        i++;
    }
    
    guessTemplate[i + 1] = '\0';
}

void updateTemplate (const char secretWord[], char guessLetter, char guessTemplate[])
{
	//   Update guessTemplate by replacing '-' in the array with
	//      guessLetter for each corresponding cell in secretWord
	//   If secretWord is kansas and guessLetter is 's'.
	//   If guessTemplate was --n--- then guessTemplate would
	//   be changed to --ns-s
    
	//   ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
    
    int i = 0;
    
    while (secretWord[i] != '\0' && guessTemplate[i] != '\0')
    {
        if (secretWord[i] == guessLetter)
        {
            guessTemplate[i] = guessLetter;
        }
        
        i++;
    }
}

bool matchTemplate ( const char secretWord[], const char guessTemplate[] )
{
	//  will return true if secretWord and guessTemplate contain the same
	//  C++ string and will return false otherwise
    
	//   ONLY ONE LOOP IS ALLOWED IN THIS FUNCTION
    
    int i = 0;
    
    while (secretWord[i] != '\0' && guessTemplate[i] != '\0')
    {
        if (secretWord[i] != guessTemplate[i])
            return false;
        
        i++;
    }
    
    return true;
}

/* Output:
 
 
 Enter the secret word: tacos
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 -----
 Guess a letter: t
 t----
 Guess a letter: o
 t--o-
 Guess a letter: s
 t--os
 Guess a letter: a
 ta-os
 Guess a letter: c
 tacos=tacos
 You guessed the word in 5 guesses
 Program ended with exit code: 0
 
 */

