/*
 * @author Josh Kennedy
 * @file extraCredit3.cpp
 * Extra Credit Numero Tres
 */

//  This program defines and tests a class named Month.
//  The class has one member variable (an integer) to represent
//  the month.  It has a constructor to set the month using
//  the first three letters in the name of the month as three
//  arguments, a constructor to set the month using an
//  integer argument (1 for January, 2 for February, and so
//  forth), a default constructor that sets the month to 1
//  (January), an output function that outputs the month as an
//  integer, an output function that outputs the month as the
//  first three letters in the name of the month.

#include <iostream>

using namespace std;

// Definition of the Month class
class Month
{
public:
    Month(char firstLetter, char secondLetter, char thirdLetter);
    // Precondition: The parameters contain the first three characters
    // in the name of the month - all lowercase.
    // Postcondition: The member variable month has been set to
    // the integer value corresponding to the letters (1 for jan,
    // (2 for feb, and so on). month is set to 0 and a message is
    // printed if the letters do not correspond to a valid month.
    
    Month(int monthNum);
    // Precondition: The parameter monthNum contains a valid
    // month number (1 - 12)
    // Postcondition: The member variable month has been set to
    // the value of the parameter monthNum.
    
    Month();
    // Sets the member variable month to 1 (defaults to January).
    
    void outputMonthNumber();
    // Postcondition: The member variable month has been output
    // to the screen if it is valid; otherwise a "not valid"
    // message is printed.
    
    void outputMonthLetters();
    // Postcondition: The first three letters of the name of the
    // month has been output to the screen if the month is
    // valid (1 - 12); otherwise a message indicating the month
    // is not valid is output.
    
private:
    int month;
};

int main ()
{
    // Variable declarations
    int monthNum;
    char letter1, letter2, letter3;    // first 3 letters of a month
    char testAgain;                    // y or n - loop control
    
    // Loop to test the constructors
    do
    {
        // Construct a default month
        cout << endl;
        cout << "Testing the default constructor ..." << endl;
        Month defaultMonth;
        defaultMonth.outputMonthNumber();
        defaultMonth.outputMonthLetters();
        
        // Construct a month using the constructor with one integer argument
        cout << endl;
        cout << "Testing the constructor with one integer argument..." << endl;
        cout << "Enter a month number: ";
        cin >> monthNum;
        
        Month testMonth1(monthNum);
        testMonth1.outputMonthNumber();
        testMonth1.outputMonthLetters();
        
        // Construct a month using the constructor with three letters
        // as arguments
        cout << endl;
        cout << "Testing the constructor with 3 letters as arguments ..." << endl;
        cout << "Enter the first three letters of a month (lowercase): ";
        cin >> letter1 >> letter2 >> letter3;
        cout << endl;
        
        Month testMonth2(letter1, letter2, letter3);
        testMonth2.outputMonthNumber();
        testMonth2.outputMonthLetters();
        
        // See if user wants to try another month
        cout << endl;
        cout << "Do you want to test again? (y or n) ";
        cin >> testAgain;
    }
    while (testAgain == 'y' || testAgain == 'Y');
    
    return 0;
}

Month::Month(char firstLetter, char secondLetter, char thirdLetter)
{
    switch(firstLetter)
    {
        case 'j':
            if (secondLetter == 'a' && thirdLetter == 'n') month = 1;
            else if (secondLetter == 'u' && thirdLetter == 'n') month = 6;
            else if (secondLetter == 'u' && thirdLetter == 'l') month = 7;
            else month = 0;
            break;
        case 'f':
            if (secondLetter != 'e' && thirdLetter != 'b') month = 0;
            else month = 2;
            break;
        case 'm':
            if (secondLetter == 'a' && thirdLetter == 'r') month = 3;
            else if (secondLetter == 'a' && thirdLetter == 'y') month = 5;
            else month = 0;
            break;
        case 'a':
            if (secondLetter == 'p' && thirdLetter == 'r') month = 4;
            else if (secondLetter == 'u' && thirdLetter == 'g') month = 8;
            else month = 0;
            break;
        case 's':
            if (secondLetter != 'e' && thirdLetter != 'p') month = 0;
            else month = 9;
            break;
        case 'o':
            if (secondLetter != 'c' && thirdLetter != 't') month = 0;
            else month = 10;
            break;
        case 'n':
            if (secondLetter != 'o' && thirdLetter != 'v') month = 0;
            else month = 11;
            break;
        case 'd':
            if (secondLetter != 'e' && thirdLetter != 'c') month = 0;
            else month = 12;
            break;
        default:
            month = 0;
            break;
    }
    
    if (!month) cerr << "provided characters are not a valid month!" << endl;
}

Month::Month(int monthNum)
{
    month = monthNum;
}

Month::Month()
{
    month = 1;
}

void Month::outputMonthNumber()
{
    if (month >= 1 && month <= 12)
        cout << "Month: " << month << endl;
    else
        cout << "Error - The month is not a valid!" << endl;
}

void Month::outputMonthLetters()
{
    switch (month)
    {
        case 1:
            cout << "Jan" << endl;
            break;
        case 2:
            cout << "Feb" << endl;
            break;
        case 3:
            cout << "Mar" << endl;
            break;
        case 4:
            cout << "Apr" << endl;
            break;
        case 5:
            cout << "May" << endl;
            break;
        case 6:
            cout << "Jun" << endl;
            break;
        case 7:
            cout << "Jul" << endl;
            break;
        case 8:
            cout << "Aug" << endl;
            break;
        case 9:
            cout << "Sep" << endl;
            break;
        case 10:
            cout << "Oct" << endl;
            break;
        case 11:
            cout << "Nov" << endl;
            break;
        case 12:
            cout << "Dec" << endl;
            break;
        default:
            cout << "Error - the month is not a valid!" << endl;
    }
}

/* output:
 
 
 Testing the default constructor ...
 Month: 1
 Jan
 
 Testing the constructor with one integer argument...
 Enter a month number: 12
 Month: 12
 Dec
 
 Testing the constructor with 3 letters as arguments ...
 Enter the first three letters of a month (lowercase): n o v
 
 Month: 11
 Nov
 
 Do you want to test again? (y or n) n
 Program ended with exit code: 0
 
 */

