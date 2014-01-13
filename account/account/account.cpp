// Account.cpp
// Member-function definitions for class Account.

#include <iostream>

using namespace std;

#include "account.h" // include definition of class Account

// Account constructor initializes data member balance
Account::Account(double initialBalance)
{
	balance = 0; // assume that the balance begins at 0
    
	// if initialBalance is greater than 0, set this value as the
	// balance of the Account; otherwise, balance remains 0
	if ( initialBalance > 0 )
		balance = initialBalance;
    
	// if initialBalance is negative, print error message
	if ( initialBalance < 0 )
        cout << "Error: Initial balance cannot be negative.\n" << endl;
} // end Account constructor

// credit (add) an amount to the account balance
void Account::credit(double amount)
{
	balance += amount; // add amount to balance
} // end function credit

// if the debit will make the balance negative,
//   leave the balance as is and display error message
void Account::debit(double amount)
{
    balance -= amount; // subtract amount from balance
    
    if (balance < 0.0)
        cerr << "insufficent funds!" << endl;
}


// return the account balance
double Account::getBalance()
{
	return balance; // gives the value of balance to the calling function
} // end function getBalance
