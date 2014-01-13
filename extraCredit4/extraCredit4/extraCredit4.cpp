/*
 * @author Josh Kennedy
 * @file extraCredit4.cpp
 * Extra Credit Numero Cuatro
 */

//  This program defines and tests a class named Month.
//  The class has one member variable (an integer) to represent
//  the month.  It has a constructor to set the month using an
//  integer argument (1 for January, 2 for February, and so
//  forth), a default constructor that sets the month to 1
//  (January), an output function that outputs the month as an
//  integer, an output function that outputs the month as the
//  first three letters in the name of the month, and a member
//  function that returns the next month.

#include <iostream>
using namespace std;

// Definition of the Month class
class Month
{
public:
    
    Month (int monthNum);
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
    
    Month nextMonth();
    // Precondition: The month is defined and valid.
    // Returns the next month as an object of type Month.
    
private:
    int month;
};

int main ()
{
    // Variable declarations
    int monthNum;
    char testAgain;                    // y or n - loop control
    
    // Loop to test the next month function
    do {
        
        cout << endl;
        cout << "Enter a month number: ";
        cin >> monthNum;
        
        Month testMonth(monthNum);
        cout << endl;
        cout << "This month is" << endl;
        testMonth.outputMonthNumber();
        testMonth.outputMonthLetters();
        
        Month next = testMonth.nextMonth();
		cout << endl;
        cout << "Next month is" << endl;
        next.outputMonthNumber();
        next.outputMonthLetters();
        
		cout << endl;
        cout << "This month is still" << endl;
        testMonth.outputMonthNumber();
        testMonth.outputMonthLetters();
        
        // See if user wants to try another month
        cout << endl;
        cout << "Do you want to test again? (y or n) ";
        cin >> testAgain;
    }
    while (testAgain == 'y' || testAgain == 'Y');
    
    return 0;
}

Month::Month()
{
    month = 1;
}

Month::Month (int monthNum)
{
    month = monthNum;
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

Month Month::nextMonth()
{
    return Month(((month < 12) ? month + 1 : ((month > 12) ? 0 : 1)));
}

/* Output:
 
 
 Enter a month number: 12
 
 This month is
 Month: 12
 Dec
 
 Next month is
 Month: 1
 Jan
 
 This month is still
 Month: 12
 Dec
 
 Do you want to test again? (y or n) y
 
 Enter a month number: 11
 
 This month is
 Month: 11
 Nov
 
 Next month is
 Month: 12
 Dec
 
 This month is still
 Month: 11
 Nov
 
 Do you want to test again? (y or n) y
 
 Enter a month number: 13
 
 This month is
 Error - The month is not a valid!
 Error - the month is not a valid!
 
 Next month is
 Error - The month is not a valid!
 Error - the month is not a valid!
 
 This month is still
 Error - The month is not a valid!
 Error - the month is not a valid!
 
 Do you want to test again? (y or n) Program ended with exit code: 9
 
 */

